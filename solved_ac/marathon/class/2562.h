//
// Created by 임혁 on 2024. 6. 19
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


bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}


void p_2562() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);


    pair<int, int> num[9];

    for (int i = 0; i < 9; ++i) {
        cin >> num[i].first;
        num[i].second = i + 1;
    }

    sort(&num[0], &num[9], comp);
    cout << num[8].first << '\n' << num[8].second;

}
