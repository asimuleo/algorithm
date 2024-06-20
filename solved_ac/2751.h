//
// Created by 임혁 on 2024. 6. 12..
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


void p_2751() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << '\n';
    }

}
