//
// Created by 임혁 on 2024. 5. 31..
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

/**
 * 설명이 필요 없다.
 */
void p_9375() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    int T;
    cin >> T;

    for (int test_case = 0; test_case < T; ++test_case) {

        map<string, vector<string>> closet;

        int n; // 의상의 수
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string name, type; // 의상의 종류와 타입
            cin >> name >> type;

            if (closet.find(type) != closet.end()) {
                closet.find(type)->second.push_back(name);
            } else {
                closet.insert({type, {name}});
            }
        }
        if (closet.empty() ) {
            cout << 0 << endl;
        } else if (closet.size() == 1) {
            cout << closet.begin()->second.size() << endl;
        } else {
            unsigned long ret = 1;
            for (const auto &item: closet)
                ret *= item.second.size() + 1;
            cout << ret - 1 << endl;
        }

    }


}