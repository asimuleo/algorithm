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


void p_13300() {
    //    cin.tie(0);
    //    ios::sync_with_stdio(0);

    // 한 방에 배정할 수 있는 최대 인원 수 K

    // 남학생은 남학생끼리, 여학생은 여학생끼리
    // 한 방에는 같은 학년의 학생들
    // 물론 한 방에 한 명만 배정하는 것도 가능


    // 학년,성별
    int table[7][2];
    memset(table, 0, sizeof(table));

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int s, y;
        cin >> s >> y;

        table[y][s]++;
    }

    int ret = 0;

    for (auto &i: table) {
        for (const int j: i) {
            ret += (j + k - 1) / k;
        }
    }

    cout << ret;


    // 필요한 방의 최소 개수
}
