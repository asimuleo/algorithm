//
// Created by 임혁 on 24. 7. 20.
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

void p_29863() {

    int a, b;
    cin >> a >> b;

    if (a >= 0 && a <= 3)
        cout << b - a;
    else
        cout << 24 - a + b;

}