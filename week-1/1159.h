//
// Created by 임혁 on 2024. 5. 28..
//

#include "algorithm"
#include <iostream>
#include <vector>
#include <cmath>
#include "cstring"

using namespace std;

/**
 * 설명이 필요 없다.
 */
void p_1159() {

    int tc;
    cin >> tc;

    int alp[26];
    memset(alp, 0, sizeof(alp));

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        alp[s[0] - 'a']++;
    }

    bool success = false;

    for (int i = 0; i < 26; ++i) {
        if (alp[i] >= 5) {
            cout << char ('a' + i);
            success = true;
        }
    }

    if (!success) {
        cout << "PREDAJA";
    }

    cout << endl;

}