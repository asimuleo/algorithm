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

void p_27566() {

    int r; // r 초마다 180도 회전
    int f; // f 초 후에 멈춘다.
    cin >> r >> f;

    /**
     * 수직이 될 수는 없다고 한다.
     * [0,90) -> up
     * (90, 180] -> down
     * (180, 270) -> down
     * (270, 360) -> up
     */

    double degree = (180.0 / r * f);
    while (degree >= 360) {
        degree -= 360;
    }

    if (degree >= 0 && degree < 90)
        cout << "up";
    else if (degree > 90 && degree <= 180)
        cout << "down";
    else if (degree > 180 && degree < 270)
        cout << "down";
    else if (degree > 270 && degree < 360)
        cout << "up";


}