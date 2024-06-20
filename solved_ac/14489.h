//
// Created by 임혁 on 2024. 6. 12..
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


void p_14489() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= c * 2) {
        cout << a + b - c * 2;
    } else {
        cout << a + b;
    }


}
