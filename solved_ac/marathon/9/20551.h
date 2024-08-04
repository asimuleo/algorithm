//
// Created by csjav on 24. 8. 4.
//

#include <cstdio>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

void p_20551() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N, M;
    cin >> N >> M;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < M; ++i) {
        int question;
        cin >> question;



        auto it = lower_bound(nums.begin(), nums.end(), question);
        if (it == nums.end() || *it != question) {
            cout << -1;
        } else {
            cout << it - nums.begin();
        }
        cout << '\n';
    }


}
