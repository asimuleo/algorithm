//
// Created by cs.javah on 2024. 8. 5.
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

void p_15059() {
    int arr[3];
    for (int i = 0; i < 3; ++i) {
        cin >> arr[i];
    }

    int ret = 0;
    for (int i = 0; i < 3; ++i) {
        int j;
        cin >> j;

        if (arr[i] < j) {
            ret += j - arr[i];
        }
    }
    cout << ret;

}
