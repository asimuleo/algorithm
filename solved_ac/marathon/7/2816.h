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


void p_2816() {

    int N;
    cin >> N;
    vector<string> channel(N);

    int kbs1;
    int kbs2;

    for (int i = 0; i < N; ++i) {
        cin >> channel[i];
        if (channel[i] == "KBS1")
            kbs1 = i;
        else if (channel[i] == "KBS2")
            kbs2 = i;
    }

    if (kbs1 < kbs2) {
        for (int i = 0; i < kbs1; ++i) {
            cout << 1;
        }
        for (int i = 0; i < kbs1; ++i) {
            cout << 4;
        }
        for (int i = 0; i < kbs2; ++i) {
            cout << 1;
        }
        for (int i = 1; i < kbs2; ++i) {
            cout << 4;
        }
    } else {
        for (int i = 0; i < kbs1; ++i) {
            cout << 1;
        }
        for (int i = 0; i < kbs1; ++i) {
            cout << 4;
        }
        for (int i = 0; i < kbs2 + 1; ++i) {
            cout << 1;
        }
        for (int i = 0; i < kbs2; ++i) {
            cout << 4;
        }
    }


}