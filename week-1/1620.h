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
void p_1620() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    map<string, int> pockets_map;

    int n, m;
    cin >> n >> m;

    vector<string> pockets(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> pockets[i];
        pockets_map.insert({pockets[i], i});
    }

    for (int i = 0; i < m; ++i) {

        string input;
        cin >> input;

        // 입력으로 숫자가 들어왔다면?
        if (isdigit(input[0])) {
            int num = stoi(input);
            cout << pockets[num] << endl;
        } else { // 입력으로 문자가 들어왔다면?
            cout << pockets_map.find(input)->second << endl;
        }

    }

}