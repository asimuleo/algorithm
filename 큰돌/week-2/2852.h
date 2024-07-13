//
// Created by cs.javah on 2024. 7. 11.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>

using namespace std;


/**
    초 덧셈 할 때, 60 더하고 60% 나누기 좋다
    초 나중에 분으로 바꿔주기
*/
void p_2852() {

    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    int N; // 골이 들어간 횟수
    cin >> N;
    int t_mm1 = 0, t_ss1 = 0, t_mm2 = 0, t_ss2 = 0;
    int p_mm1 = 0, p_ss1 = 0, p_mm2 = 0, p_ss2 = 0;
    int mm = 0, ss = 0;


    int table = 0;

    int team;
    cin >> team;

    if (team == 1) {
        table++;
        scanf("%d:%d", &p_mm1, &p_ss1);
    } else {
        table--;
        scanf("%d:%d", &p_mm2, &p_ss2);
    }


    for (int i = 0; i < N - 1; i++) {
        cin >> team;
        scanf("%d:%d", &mm, &ss);


        // 양
        if ((table > 0 && team == 1) || (table == 1 && team == 2)) {
            t_mm1 += mm - p_mm1;
            if (ss < p_ss1)
                t_mm1--;
            t_ss1 += (ss - p_ss1 + 60) % 60;
        }

        //음
        if ((table < 0 && team == 2) || (table == -1 && team == 1)) {
            t_mm2 += mm - p_mm2;
            if (ss < p_ss2)
                t_mm2--;
            t_ss2 += (ss - p_ss2 + 60) % 60;
        }

        if (team == 1) {
            table++;
            p_mm1 = mm;
            p_ss1 = ss;
        } else {
            table--;
            p_mm2 = mm;
            p_ss2 = ss;
        }


    }

    mm = 48;
    ss = 0;

    // 양
    if (table > 0) {
        t_mm1 += mm - p_mm1;
        if (ss < p_ss1)
            t_mm1--;
        t_ss1 += (ss - p_ss1 + 60) % 60;
    }

    //음
    if (table < 0) {
        t_mm2 += mm - p_mm2;
        if (ss < p_ss2)
            t_mm2--;
        t_ss2 += (ss - p_ss2 + 60) % 60;
    }

    t_mm1 += t_ss1 / 60;
    t_ss1 = t_ss1 % 60;

    t_mm2 += t_ss2 / 60;
    t_ss2 = t_ss2 % 60;

    printf("%02d:%02d\n", t_mm1, t_ss1);
    printf("%02d:%02d", t_mm2, t_ss2);

}