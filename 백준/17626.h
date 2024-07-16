//
// Created by 임혁 on 24. 7. 16.
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

void p_17626() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin >> n;

    vector<int> pows(224);

    for (int i = 0; i < 224; ++i) {
        pows[i] = i * i;
    }

    for (int i = 0; i < 224; ++i) {
        if (n == pows[i]) {
            cout << 1;
            return;
        }
    }

    for (int i = 0; i < 224; ++i) {
        for (int j = 0; j < 224; ++j) {
            if (n == pows[i] + pows[j]) {
                cout << 2;
                return;
            }
        }
    }

    for (int i = 0; i < 224; ++i) {
        for (int j = 0; j < 224; ++j) {
            for (int k = 0; k < 224; ++k) {
                if (n == pows[i] + pows[j] + pows[k]) {
                    cout << 3;
                    return;
                }
            }
        }
    }

    cout << 4;
}
