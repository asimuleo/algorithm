//
// Created by cs.javah on 2024. 7. 12.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;


/**
	티어 1어 속하지 않는 캐릭터 수 + 캐릭터와 16번째캐릭터의 투표수 차이가 1000이하일 경우
*/
void p_30791() {

    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    int tier1;
    cin >> tier1;

    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int character;
        cin >> character;

        if (tier1 - character <= 1000) ret++;
    }

    cout << ret;

}