//
// Created by 임혁 on 2024. 5. 31..
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

/**
 * 설명이 필요 없다.
 */
void p_1213() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);


    string s;
    cin >> s;

    int alphabet[26];
    memset(alphabet, 0, sizeof(alphabet));

    for (char i: s) {
        alphabet[i - 'A']++;
    }

    int odd_cnt = 0;

    for (int &i: alphabet) {
        if (i % 2 == 1) {
            odd_cnt++;
        }
    }

    if (odd_cnt >= 2) {
        cout << "I'm Sorry Hansoo";
    } else {

        vector<char> ret;
        char unique = '?';

        for (int i = 0; i < 26; ++i) {
            if (alphabet[i] % 2 == 1) {
                unique = char('A' + i);
            }

            for (int j = 0; j < alphabet[i] / 2; ++j) {
                ret.push_back(char('A' + i));
            }
        }

        for (char i : ret) {
            cout << i;
        }
        if (unique != '?') {
            cout << unique;
        }
        reverse(ret.begin(), ret.end());
        for (char i : ret) {
            cout << i;
        }
    }

}