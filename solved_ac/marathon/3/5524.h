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


void p_5524() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            cout << (char) tolower(s[j]);
        }
        cout << endl;
    }


}
