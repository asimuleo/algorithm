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


void p_1152() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    string s;
    getline(cin, s);

    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);

    if (s.empty()) {
        cout << 0 << endl;
    } else {
        cout << count(s.begin(), s.end(), ' ') + 1 << endl;
    }

}
