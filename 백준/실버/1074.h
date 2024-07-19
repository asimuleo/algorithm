//
// Created by cs.javah on 2024. 7. 17.
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

int N, r, c;

void play(int y, int x, int n, int &ret) {
    if (y == r && x == c) {
        cout << ret;
        return;
    }

    if (n == 1)
        return;

    if (c < x + n / 2 && r < y + n / 2) {
        play(y, x, n / 2, ret);
    } else if (c >= x + n / 2 && r >= y + n / 2) {
        ret = ret + (n * n / 4 * 3);
        play(y + n / 2, x + n / 2, n / 2, ret);
    } else if (c >= x + n / 2) {
        ret = ret + (n * n / 4);
        play(y, x + n / 2, n / 2, ret);
    } else {
        ret = ret + (n * n / 2);
        play(y + n / 2, x, n / 2, ret);
    }
}


void p_1074() {
    cin >> N >> r >> c;
    int ret = 0;

    play(0, 0, pow(2, N), ret);
}

