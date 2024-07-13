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


void p_30087() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (s == "Algorithm")
            cout << "204" << endl;
        if (s == "DataAnalysis")
            cout << "207" << endl;
        if (s == "ArtificialIntelligence")
            cout << "302" << endl;
        if (s == "CyberSecurity")
            cout << "B101" << endl;
        if (s == "Network")
            cout << "303" << endl;
        if (s == "Startup")
            cout << "501" << endl;
        if (s == "TestStrategy")
            cout << "105" << endl;

    }


}
