//
// Created by cs.javah on 2024. 8. 1.
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
bool sacks[10];
void p_28431() {

    for (int i = 0; i < 5; ++i) {
        int a;
        cin >> a;
        sacks[a] = !sacks[a];
    }
    for (int i = 0; i < 10; ++i) {
        if (sacks[i])
            cout << i;
    }
}