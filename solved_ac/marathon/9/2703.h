//
// Created by csjav on 24. 8. 4.
//

#include <cstdio>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

// Cryptoquote
void p_2703() {
    int T;
    cin >> T;
    cin.ignore();

    for (int test_case = 0; test_case < T; ++test_case) {
        string from, rule;
        getline(cin, from);
        getline(cin, rule);

        for (auto c: from) {
            if (c == ' ') {
                cout << c;
            } else {
                cout << rule[c - 'A'];
            }
        }
        cout << endl;
    }
}
