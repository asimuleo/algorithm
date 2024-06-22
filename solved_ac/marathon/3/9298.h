//
// Created by 임혁 on 2024. 6. 22.
// https://www.acmicpc.net/problem/9298
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


void p_9298() {
    //    cin.tie(0);
    //    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case) {
        int n; // 개미의 수
        cin >> n;

        double max_x = -1001.0, max_y = -1001.0;
        double min_x = 1001.0, min_y = 1001.0;


        while (n-- > 0) {
            double x, y; // 개미의 위치
            cin >> x >> y;
            max_x = max(x, max_x);
            max_y = max(y, max_y);

            min_x = min(x, min_x);
            min_y = min(y, min_y);
        }

        double perimeter = (max_x - min_x) * 2 + (max_y - min_y) * 2;
        double area = (max_x - min_x) * (max_y - min_y);

        // 출력 예제
        // Case 1: Area 94.5, Perimeter 43.5
        // Case 2: Area 40.85, Perimeter 26.7
        cout << fixed;
        cout.precision(3);
        cout << "Case " << test_case << ": Area " << area << ", Perimeter " << perimeter << endl;

    }
}
