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


void p_2083() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    string s;
    int age, weight;

    while(1) {
        cin >> s >> age >> weight;
        if (s == "#")
            break;
        cout << s << ' ';
        if (age > 17 || weight >= 80) {
            cout << "Senior" << endl;
        } else {
            cout << "Junior" << endl;
        }
    }




}
