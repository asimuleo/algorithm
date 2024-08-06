//
// Created by 임혁 on 24. 8. 06.
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
#include <climits>

using namespace std;

void p_18788() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int a1, a2;
    cin >> a1 >> a2;

    int b1, b2;
    cin >> b1 >> b2;

    // K = K % 4;

    vector<int> nums;

    for (int i = 1; i <= N; ++i) {
        nums.push_back(i);
    }
    vector<int> temp = nums;

    // K 번 만큼 하자!
    for (int i = 0; i < K; ++i) {
        reverse(nums.begin() + a1 - 1, nums.begin() + a2);
        reverse(nums.begin() + b1 - 1, nums.begin() + b2);
        if (temp == nums) {
            int k = K % (i + 1);
            for (int j = 0; j < k; ++j) {
                reverse(temp.begin() + a1 - 1, temp.begin() + a2);
                reverse(temp.begin() + b1 - 1, temp.begin() + b2);
            }
            for (int j = 0; j < N; ++j) {
                cout << temp[j] << '\n';
            }
            return;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << nums[i] << '\n';
    }


}