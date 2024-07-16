//
// Created by cs.javah on 2024. 7. 16.
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

using namespace std;


void play() {
    int k;
    cin >> k;

    vector<string> nums(k);

    for (int i = 0; i < k; ++i) {
        cin >> nums[i];
    }

    for (int i = 0; i < k - 1; ++i) {
        for (int j = i + 1; j < k; ++j) {
            string s1 = nums[i] + nums[j];
            string s2 = nums[i] + nums[j];
            reverse(s2.begin(), s2.end());
            if (s2 == s1) {
                cout << s1 << endl;
                return;
            }
            string s3 = nums[j] + nums[i];
            string s4 = nums[j] + nums[i];
            reverse(s4.begin(), s4.end());
            if (s3 == s4) {
                cout << s3 << endl;
                return;
            }
        }
    }

    cout << 0 << endl;
}


/**
*   비밀번호는 k개의 단어 중에서 두 단어를 합쳐야 되고, 팰린드롬이어야 한다.
*   단어 k개 주어졌을 때, 팰린드롬을 찾는 프로그램을 작성하시오.
*
*/
void p_8892() {
    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        play();
    }
}
