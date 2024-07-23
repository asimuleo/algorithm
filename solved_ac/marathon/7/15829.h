//
// Created by 임혁 on 24. 7. 22.
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

void p_15829() {

    long long size;
    cin >> size;

    string s;
    cin >> s;

    // mod * mod cs 2**63
    // 1.5241579e+18 vs 9.223372e+18

    long long mod = 1234567891;
    long long ret = 0;
    long long i31 = 1;
    for (int i = 0; i < s.size(); ++i) {
        int current = s[i] - 'a' + 1;
        ret += current * i31;
        i31 = i31 * 31 % mod;
        ret = ret % mod;
    }
    cout << ret % mod;


}