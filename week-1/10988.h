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
void p_10988() {


    string s;
    cin >> s;
    for (int i = 0; i < s.size() / 2; ++i) {
        if ( s[i] != s[s.size() - i - 1]) {
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;

}