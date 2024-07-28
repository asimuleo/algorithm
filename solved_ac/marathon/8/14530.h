//
// Created by 임혁 on 24. 7. 27.
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

void p_14530() {

    int x, y;
    cin >> x >> y;

    int step = 1;

    int total_distance = 0;

    int current_position = x;

    bool positive = true;

    while (true) {

        if (positive) {
            // step 이 다할 때 까지 이동한다.
            for (int i = current_position; i < x + step; ++i) {
                current_position++; // 현재 위치 증가
                total_distance++; // 총 거리 증가
                if (current_position == y) {
                    cout << total_distance;
                    return;
                }
            }
        } else {
            // step 이 다할 때 까지 이동한다.
            for (int i = current_position; i > x - step; --i) {
                current_position--; // 현재 위치 증가
                total_distance++; // 총 거리 증가
                if (current_position == y) {
                    cout << total_distance;
                    return;
                }
            }
        }

        positive = !positive;
        step *= 2;

    }


}
