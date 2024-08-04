//
// Created by csjav on 24. 8. 4.
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

long long nn(long long a) {
    return a * (a + 1) / 2;
}

//  a <= b;
void play(long long a, long long b) {
    if (a >= 0 && b >= 0) {
        // 둘다 양수
        cout << nn(b) - nn(a) + a;
    } else if (b >= 0) {
        // b 만 양수
        cout << nn(b) - nn(abs(a));
    } else {
        // 둘다 음수
        cout << -nn(abs(a)) + nn(abs(b)) + b;
    }
}

void p_2355() {
    long long a, b;
    cin >> a >> b;

    if (a >= b) {
        play(b, a);
    } else {
        play(a, b);
    }
}
