//
// Created by 임혁 on 2024. 6. 1..
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
void p_1940() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);


    int n; // 필요한 재료의 개수 <= 15,000
    int m; // 갑옷을 만드는 데 필요한 수 <= 10,000,000
    cin >> n >> m;
    vector<int> ingredients(n); // n 개의 고유한 번호 <= 100,000
    for (int i = 0; i < n; ++i) {
        cin >> ingredients[i];
    }

    // 첫째 줄에 갑옷을 만들 수 있는 개수를 출력한다.

    /**
     * 갑옷은 2개의 재료로 만들 수 있으니까
     * 2중 반복문을 돌면서 i, j의 합이 m 이 되는 수를 찾는다.
     * j 는 음수 처리를 해서 반복문을 돌 때 음수는 건너 뛰도록 한다.
     */

    int ret = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (ingredients[i] < 0) {
            continue;
        }
        for (int j = i + 1; j < n; ++j) {
            if (ingredients[j] < 0) {
                continue;
            }
            if (ingredients[i] + ingredients[j] == m) {
                ret++;
                ingredients[j] = -1;
                break;
            }
        }
    }
    cout << ret;
}