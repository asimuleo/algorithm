//
// Created by csjav on 24. 6. 28.
//


#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void p_2774() {

    int t;
    cin >> t;
    for (int test_case = 0; test_case < t; ++test_case) {
        string n;
        cin >> n;
        int arr['9' - '0' + 1];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n.size(); ++i) {
            arr[n[i] - '0']++;
        }
        int ret = 0;
        for (int i = 0; i < '9' - '0' + 1; ++i) {
            if (arr[i] != 0) ret++;
        }
        cout << ret << endl;
    }


}