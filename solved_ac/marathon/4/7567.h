//
// Created by csjav on 24. 6. 28.
//


#include <iostream>
#include <cmath>

using namespace std;

void p_7567() {

    string s;
    cin >> s;

    int stack = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == s[i]) stack++;
    }

    cout << s.size() * 10 - stack * 5 << endl;

}