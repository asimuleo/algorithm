//
// Created by 임혁 on 24. 7. 16.
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

void p_1253() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N);
    vector<pair<int, pair<int, int> > > sums;


    int ret = 0;

    cin >> nums[0];

    for (int i = 1; i < N; ++i) {
        cin >> nums[i];
        for (int j = 0; j < i; ++j) {
            sums.push_back({nums[i] + nums[j], {i, j}});
        }
    }

    sort(sums.begin(), sums.end());

    auto cmp = [](const pair<int, pair<int, int> > &x, const pair<int, pair<int, int> > &y) {
        return x.first < y.first;
    };


    for (int i = 0; i < N; ++i) {
        pair<int, pair<int, int> > p = {nums[i], {0, 0}};
        auto it = lower_bound(sums.begin(), sums.end(), p, cmp);

        if (it != sums.end()) {
            while (it->first == nums[i]) {
                if (it->second.first != i && it->second.second != i) {
                    ret++;
                    break;
                }
                ++it;
            }
        }
    }

    // 0이 있는데 자기자신을 또찾는다..


    cout << ret;
}
