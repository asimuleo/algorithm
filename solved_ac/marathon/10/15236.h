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

void p_15236() {

    int n;
    cin >> n;

    int ret = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            ret += i + j;
        }
    }

    cout << ret;

}