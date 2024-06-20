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
void p_11655() {


    string s;
    getline(cin, s);

    for (auto c: s) {
        if (c >= 'a' && c <= 'z') {
            cout << char((c - 'a' + 13) % 26 + 'a');
        }
        else if (c >= 'A' && c <= 'Z') {
            cout << char((c - 'A' + 13) % 26 + 'A');
        }
        else {
            cout << c;
        }
    }
    cout << endl;

}