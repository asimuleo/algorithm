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
void p_10808() {

    string s;
    cin >> s;

    int ret[26];
    memset(ret, 0, sizeof(ret));

    for (auto c: s) {
        ret[c - 'a']++;
    }

    for (int i = 0; i < 26; ++i) {
        cout << ret[i] << ' ';
    }

}