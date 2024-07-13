//
// Created by 임혁 on 2024. 5. 28..
//

#include "algorithm"
#include <iostream>
#include <vector>
#include <cmath>
#include "cstring"

using namespace std;

/**
 * 설명이 필요 없다.
 */
void p_2559() {


    int n, k;
    cin >> n >> k;

    vector<int> tem(n);
    for (int i = 0; i < n; ++i) {
        cin >> tem[i];
    }

    int ret = 0;

    for (int i = 0; i < k; ++i) {
        ret += tem[i];
    }

    int temp = ret;

    for (int i = 0; i < n - k; ++i) {
        temp = temp - tem[i] + tem[i + k];
        ret = max(ret, temp);
    }

    cout << ret << endl;

}