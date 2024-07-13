//
// Created by 임혁 on 2024. 6. 20.
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


void p_2675() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int r;
        cin >> r;
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            for (int k = 0; k < r; ++k) {
                cout << s[j];
            }
        }
        cout << endl;

    }


}
