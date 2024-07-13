//
// Created by 임혁 on 2024. 6. 26.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>

using namespace std;


void p_13118() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    vector<int> ps;

    for (int i = 0; i < 4; ++i) {
        int p;
        cin >> p;
        ps.push_back(p);
    }

    int x;
    cin >> x;

    auto it = std::find(ps.begin(), ps.end(), x);
    if (it == ps.end()) {
        cout << 0 << endl;
    } else {
        cout << it - ps.begin() + 1 << endl;
    }

}
