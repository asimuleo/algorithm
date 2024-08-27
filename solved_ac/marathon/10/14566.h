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

void p_14566() {

    int n;
    cin >> n;

    int stop[n];

    for (int i = 0; i < n; ++i) {
        cin >> stop[i];
    }

    sort(stop, stop + n);

    int distance = 32800002;

    for (int i = 1; i < n; ++i) {
        if(distance > stop[i] - stop[i-1]) {
            distance = stop[i] - stop[i - 1];
        }
    }

    int number = 0;

    for (int i = 1; i < n; ++i) {
        if(distance == stop[i] - stop[i-1]) {
            number++;
        }
    }

    cout << distance << ' ' << number;
}