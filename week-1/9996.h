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
void p_9996() {

    int tc;
    cin >> tc;
    cin.ignore();
    string pre, suf;
    getline(cin, pre, '*');
    cin >> suf;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;

        if (pre.size() + suf.size() > s.size()) {
            cout << "NE" << endl;
            continue;
        }

        bool ret = true;

        for (int j = 0; j < pre.size(); ++j) {
            if (s[j] != pre[j]) {
                ret = false;
                break;
            }
        }

        if (ret) {
            for (int j = 0; j < suf.size(); ++j) {
                if (s[s.size() - j - 1] != suf[suf.size() - j - 1]) {
                    ret = false;
                    break;
                }
            }
        }

        if (ret) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }



    }



}