//
// Created by 임혁 on 2024. 5. 24..
//


/**
 * 문제 9.12 웨브바짐
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

long e;  // 지금 계란 가격 (1 <= e <= 10^14)
int m; // 마지막 계란 가격이 m의 배수  (1 <= m <= 20)

// 10! = 3628800 까지는 가능해 보임
long cache[1000000];

void pre_cals() {
    fill_n(cache, 1000000, -1);
}

// 사전순 번호를 반환한다.
// step 은 최대 6 임을 가정한다.
long getIndex(string &X, int step) {
    string s = X.substr(0, step);
    return stol(s);
}

// 가능한 가격의 경우의 수를 반환

/**
 *
 * 하나씩 만들어가면 step 대신에 해당 스트링의 길이로
 *
 *
 *
 * @param str_e
 * @param step
 * @return
 */
long possible_cnt(string &str_e, int step) {

    if (step <= 6 && step >= 1 && cache[getIndex(str_e, step)] != -1) {
        return cache[getIndex(str_e, step)];
    }

    if (step == str_e.size() - 1) {
        long temp_e = stol(str_e);
        if (temp_e >= e) {
            return 0l;
        }
        if (temp_e % m == 0) {
            return 1l;
        } else {
            return 0l;
        }
    }

    long ret = 0;

    // swap(step, step)
    ret += possible_cnt(str_e, step + 1);

    bool pass[10];
    memset(pass, 0, sizeof(pass));

    for (int j = step + 1; j < str_e.size(); ++j) {

        if (str_e[step] == str_e[j]) {
            continue;
        }

        int num = str_e[j] - '0';
        if (!pass[num]) {
            pass[num] = true;
        } else {
            continue;
        }

        swap(str_e[step], str_e[j]);
        long temp_e = stol(str_e);
        if (temp_e < e) { // 이전 가격이 현재 가격보다 작아야 한다.
            ret += possible_cnt(str_e, step + 1);
        }
        swap(str_e[step], str_e[j]);
    }

    if (step <= 6 && step >= 1) {
        cache[getIndex(str_e, step)] = ret;
    }
    return ret;

}

/**
 * 1. 이전 계란 가격은 e보다 항상 작아야 한다.
 * 2. 이전 계란 가격은 0으로 시작 할 수 있습니다.
 *
 * 각 테스트 케이스마다 한 줄에 가능한 가격의 수를 1,000,000,007 (10억7)으로 나눈 나머지를 출력
 */

void zimbabwe() {

    pre_cals();

    int T;
    cin >> T;
    for (int tet_case = 0; tet_case < T; ++tet_case) {
        cin >> e;
        string str_e = to_string(e);
        cin >> m;


        cout << possible_cnt(str_e, 0) % 1000000007 << endl;


    }

}