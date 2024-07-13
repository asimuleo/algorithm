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

using namespace std;


void p_18698() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int j;
        for (j = 0; j < s.size(); ++j) {
            if (s[j] == 'D') {
                cout << j << endl;
                break;
            }
        }
        if (j == s.size() && s[j - 1] != 'D') {
            cout << j << endl;
        }
    }
}
