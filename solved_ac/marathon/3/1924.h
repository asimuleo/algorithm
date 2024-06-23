//
// Created by 임혁 on 2024. 6. 23.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <iomanip>
#include <list>


using namespace std;


void p_1924() {
    //    cin.tie(0);
    //    ios::sync_with_stdio(0);

    int month[12] = {
        31, 28, 31, 30, 31, 30, 31,
        31, 30, 31, 30, 31
    };

    string days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};


    //  x월 y일
    int x, y;
    cin >> x >> y;

    int count = 0;

    for (int i = 1; i < x; ++i) {
        count += month[i - 1];
    }


    count += y - 1;


    int ret_index = 0;

    while (count-- > 0) {
        ret_index++;
        if (ret_index == 7) {
            ret_index = 0;
        }
    }

    cout << days[ret_index];
}
