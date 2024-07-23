//
// Created by 임혁 on 24. 7. 22.
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
#include <cstring>

using namespace std;


int cnt[30];

void p_1371() {


    string s;
    while(cin >> s) {
        for (char c: s) {
            if (c == ' ')
                cnt[29]++;
            else
                cnt[c-'a']++;
        }
    }

    int max_index = 0;
    for (int i = 1; i < 30; ++i) {
        if (cnt[i] > cnt[max_index]) {
            max_index = i;
        }
    }

    for (int i = 0; i < 30; ++i) {
        if (cnt[i] == cnt[max_index])
            cout << char ('a' + i);
    }


}