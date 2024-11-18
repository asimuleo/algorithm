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


int main() {
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
