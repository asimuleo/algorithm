//
// Created by 임혁 on 2024. 6. 13..
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <iomanip>

using namespace std;


void p_25238() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    int a, b;
    cin >> a >> b;

    if(a - double (b) / 100 * a >= 100) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }


}
