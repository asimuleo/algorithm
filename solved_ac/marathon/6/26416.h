//
// Created by cs.javah on 2024. 7. 12.
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

bool least_7_characters(string &s) {
    return s.size() < 7;
}

bool least_one_upper(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') return false;
    }
    return true;
}

bool least_one_lower(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if ('a' <= s[i] && s[i] <= 'z') return false;
    }
    return true;
}

bool least_one_digit(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) return false;
    }
    return true;
}

// #, @, *, and &
bool least_one_special(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if ('#' == s[i] || s[i] == '@' || s[i] == '*' || s[i] == '&') return false;
    }
    return true;
}


/**

*/
void p_26416() {

    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int size;
        cin >> size;

        string s;
        cin >> s;


        if (least_one_upper(s)) {
            s.append(string(1, 'A'));
        }
        if (least_one_lower(s)) {
            s.append(string(1, 'a'));
        }
        if (least_one_digit(s)) {
            s.append(string(1, '1'));
        }
        if (least_one_special(s)) {
            s.append(string(1, '#'));
        }
        if (least_7_characters(s)) {
            s.append(string(7 - s.size(), '1'));
        }

        cout << "Case #" << t + 1 << ": " << s << endl;
    }

}