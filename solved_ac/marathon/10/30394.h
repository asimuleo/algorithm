//
// Created by 임혁 on 24. 8. 13.
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

void p_30394() {

    int N;
    cin >> N;

    int min = 1000000001;
    int max = -1000000001;

    int x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        if (min > y) min = y;
        if (max < y) max = y;
    }

    cout << max - min;

}