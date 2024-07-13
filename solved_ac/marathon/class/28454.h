//
// Created by 임혁 on 2024. 6. 21.
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

struct date {
    int year;
    int month;
    int date;
};

// a <= b
bool isAfter(date a, date b) {
    if (a.year > b.year) {
        return false;
    } else if (a.year == b.year) {
        if (a.month > b.month) {
            return false;
        } else if (a.month == b.month) {
            if (a.date > b.date) {
                return false;
            } else {
                return true;
            }
        } else {
            return true;
        }
    } else {
        return true;
    }
}

// 항상 2월은 28
void p_28454() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);
    int ret = 0;

    date now{};
    scanf("%d-%d-%d", &now.year, &now.month, &now.date);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        date gift{};
        scanf("%d-%d-%d", &gift.year, &gift.month, &gift.date);
        if(isAfter(now, gift)) ret++;
    }

    printf("%d", ret);


}
