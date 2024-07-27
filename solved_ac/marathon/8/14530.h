//
// Created by 임혁 on 24. 7. 27.
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

void p_14530() {
    int total_distance = 0;

    int x, y;
    cin >> x >> y;

    int step = 0;


    while (abs(x - y) > pow(2, step++)) {
    }

    if (step % 2 == 0) {
        step++;
    }

    for (int i = 0; i < step; ++i) {
        if (i % 2 == 0 && x - i < 0) {
            total_distance += x * 2;
            continue;
        }
        if (i % 2 == 1 && x + i > 1000) {
            total_distance += (1000 - x) * 2;
            continue;
        }
        total_distance += i * 2;
    }

    total_distance += abs(x - y);

    cout << total_distance;
}
