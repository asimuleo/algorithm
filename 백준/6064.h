//
// Created by cs.javah on 2024. 7. 18.
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

void p_6064() {
    int T;
    cin >> T;
    for (int test_case = 0; test_case < T; ++test_case) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int s = min(M, N);

        int a = 0;
        int b = 0;

        while (b > 0) {
            x += s;
            y += s;
            a = x % M;
            b = y % N;
            if (a == b) {
                cout <<
            }
        }


    }
}
