//
// Created by cs.javah on 2024. 7. 18.
//


#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

// R은 배열에 있는 수의 순서를 뒤집는 함수
// D는 첫 번째 수를 버리는 함수


void play(string &p, vector<int> &nums) {
    bool front = true;

    int l = 0;
    int r = nums.size();

    // 함수부
    for (int i = 0; i < p.size(); i++) {
        char p1 = p[i];

        int cnt = 0;
        int next = i;
        while (p[i] == p[next]) {
            next++;
            cnt++;
        }

        i = next-1;

        if (p1 == 'R') {
            if (cnt % 2 == 1)
                front = !front;
        } else if (p1 == 'D') {
            // D
            if (l == r) {
                cout << "error" << endl;
                return;
            }

            if (front)
                l += cnt;
            else
                r -= cnt;
        }
    }

    if (l > r) {
        cout << "error" << endl;
        return;
    }


    // 출력부
    if (front) {
        // 출력부
        cout << "[";
        if (l < r) {
            cout << nums[l];
        }
        for (int i = l + 1; i < r; ++i) {
            cout << "," << nums[i];
        }
        cout << "]" << endl;
    } else {
        // 출력부
        cout << "[";
        if (l < r) {
            cout << nums[r - 1];
        }
        for (int i = r - 2; i >= l; --i) {
            cout << "," << nums[i];
        }
        cout << "]" << endl;
    }
}


/**
 * 처음에 읽었을 떄는 단순 구현 문제인지 알고 구현을 했다.
 * 단순 구현 문제는 맞았는데, 입력 문자열 처리가 꽤 어려운 문제였던 것 같다.
 * istringstream 을 쓰는 게 효율적이였다.
 * 스트링을 , 기준으로 split 하려고 했는데, 시간초과가 나는 걸보니 꽤 무거운 작업인 것 같다.
 * 나는 문자열을 지울 떄, 실제로 지우는 대신에  인덱스만 변경했는데
 * deque 를 사용해서 지웠으면 시간도 빠르고 로직도 가벼웠을 것 같다.
 */
void p_5430() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int test_case = 0; test_case < T; ++test_case) {
        string p;
        cin >> p;
        int n;
        cin >> n;

        string s;
        cin >> s;
        s = s.substr(1, s.size() - 2);

        replace(s.begin(), s.end(), ',', ' ');


        istringstream sst(s);


        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            sst >> nums[i];
        }



        play(p, nums);
    }
}
