//
// Created by 임혁 on 2024. 6. 25..
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


void p_10818() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cout << nums[0] << ' ' << nums[n - 1] << endl;

}
