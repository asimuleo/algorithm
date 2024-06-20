//
// Created by 임혁 on 2024. 6. 14..
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <iomanip>
#include <list>

using namespace std;


void p_10250() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int test_case = 0; test_case < t; ++test_case) {
        int h, w, n;
        cin >> h >> w >> n;

        if (h >= n) {
            cout << to_string(n) + "01" << endl;
        } else {
            int quotient = ((n - 1) / h) + 1;
            int remainder = ((n - 1) % h) + 1;

            if (quotient < 10) {
                cout << to_string(remainder) + "0" + to_string(quotient) << endl;
            } else {
                cout << to_string(remainder) + to_string(quotient) << endl;
            }
        }
    }
}
