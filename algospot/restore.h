//
// Created by 임혁 on 2024. 6. 20.
//


/**
 * 문제 9.14 실험 데이터 복구하기
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <iomanip>

using namespace std;

vector<string> ks; // 모든 부분 문자열
int overlap[15][15]; // a 조각 뒤에 b 조각이 올때, 겹치는 수의 최대 값
int cache[15][1 << 15]; // restore 함수의 메모이제이션


/**
 * 모든 문자열에 대해 그 문자열이 다른 문자열에 포함 된다면 그 문자열은 답에 영향이 없다.
 */
vector<string> compression(vector<string> &v) {
    vector<string> compressed;

    for (int i = 0; i < v.size(); ++i) {
        bool push = true;
        for (int j = 0; j < v.size(); ++j) {
            if (i == j) {
                continue;
            }
            // 문자열 i 가 어느 한 문자열에라도 포함이 된다면 push = false;
            if (v[j].find(v[i]) != string::npos) {
                push = false;
                break;
            }
        }
        if (push) {
            compressed.push_back(v[i]);
        }
    }

    return compressed;
}

/**
 * restore 함수의 메모이제이션인 cache 를 초기화 하는 함수
 */
void init_cache() {
    memset(cache, -1, sizeof(cache));
}

/**
 * overlap 을 미리 구한다.
 * a 조각 뒤에 b
 */
void pre_overlap(vector<string> &v) {
    memset(overlap, 0, sizeof(overlap));
    for (int a = 0; a < v.size(); ++a) {
        for (int b = 0; b < v.size(); ++b) {
            if (a == b) {
                continue;
            }

            int index = (int) min(v[a].size(), v[b].size());

            for (int i = index; i > 0; --i) {
                string s = v[b].substr(0, i);
                string s2 = v[a].substr(v[a].size() - i);

                if (s == s2) {
                    overlap[a][b] = i;
                    break;
                }
            }
        }
    }
}

/**
 * 마지막에 출현한 조각 last 와 지금까지 출현한 조각의 집합 used 가 주어질때 , 나머지 조각을 추가해서 얻을 수 있는 overlaps()의 최대 합
 *
 * 메모이제이션이 된다.
 *
 * @param last 마지막에 출현한 string 의 index 를 의미한다.
 * @param used 지금까지 사용한 string 을 bool 배열에 표시할 때, 이를 int 로 표현했다.
 * @return 지끔까지 사용되지 않은 조각들을 사용했을때 얻을 수 있는 overlaps() 의 최대 값.
 */
int restore(int last, int used) {

    // 기저사례: 모든 조각들을 다 사용했을 때, 0을 반환
    if (used == (1 << ks.size()) - 1) {
        return 0;
    }

    // 메모이제이션
    int &ret = cache[last][used];

    if (ret != -1) {
        return ret;
    }

    // 모든 후보 조각들에 대하여, 가장 overlap 이 큰 후보를 선택한다.
    for (int next = 0; next < ks.size(); ++next) {
        if ((used & (1 << next)) == 0) { // 사용하지 않았을때만.
            ret = max(ret, overlap[last][next] + restore(next, used + (1 << next)));
        }
    }

    return ret;

}

/**
 * 문자열을 다시 재구성한다.
 */
string reconstruct(int last, int used) {

    // 기저사례: 모든 조각들을 다 사용했을 때, 빈 문자열을 반환
    if (used == (1 << ks.size()) - 1) {
        return "";
    }

    for (int next = 0; next < ks.size(); ++next) {
        if ((used & (1 << next))) {
            continue;
        }
        if (restore(last, used) == overlap[last][next] + restore(next, used + (1 << next))) {
            return ks[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next));
        }
    }

    return "응 그럴리 없어";
}


void solve() {

    int C; // 테스트 케이스
    cin >> C;

    for (int test_case = 0; test_case < C; ++test_case) {
        int k; // 부분 문자열의 수
        cin >> k;

        ks = {}; // ks 초기화

        for (int i = 0; i < k; ++i) {
            string s;
            cin >> s;
            ks.push_back(s);
        }

        ks = compression(ks); // 모든 문자열에 대해 그 문자열이 다른 문자열에 포함 된다면 그 문자열은 답에 영향이 없다.
        pre_overlap(ks);
        init_cache();

        int max_restore = -1;
        int max_start;
        // 시작 문자열을 지정해줘야 한다.
        for (int i = 0; i < ks.size(); ++i) {
            int r = restore(i, 1 << i);
            if (max_restore < r) {
                max_restore = r;
                max_start = i;
            }
        }

        cout << ks[max_start] + reconstruct(max_start, 1 << max_start) << endl;

    }

}