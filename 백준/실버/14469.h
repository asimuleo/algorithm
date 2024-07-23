//
// Created by cs.javah on 2024. 7. 23.
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

using namespace std;

void p_14469() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << 0;
        return ;
    }

    vector<pair<int, int> > cows(N);

    for (int i = 0; i < N; ++i) {
        cin >> cows[i].first;
        cin >> cows[i].second;
    }

    sort(cows.begin(), cows.end(),
         [](pair<int, int> a, pair<int, int> b) -> bool {
             if (a.first == b.first) {
                 return a.second < b.second;
             }
             return a.first < b.first;
         });

    int ret = cows[0].first + cows[0].second;

    for (int i = 1; i < N; ++i) {
        if (cows[i].first <= ret) {
            ret = ret + cows[i].second;
        } else {
            ret = cows[i].first + cows[i].second;
        }
    }

    cout << ret;



}
