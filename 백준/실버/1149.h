//
// Created by SSAFY on 24. 9. 3.
//

#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int cost[1001][3];
int N;

int cache[1001][3];

int play(int start, int past) {
    if (start == N) {
        return 0;
    }

    int &ret = cache[start][past];
    if (ret != -1) return ret;

    ret = INT_MAX;

    for (int i = 0; i < 3; ++i) {
        if (past == i) continue;
        ret = min(ret, cost[start][i] + play(start + 1, i));
    }

    return ret;
}

int p_1149() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    memset(cache, -1, sizeof(cache));


    cout << min(play(0, 0), min(play(0, 2), play(0, 1)));
    return 0;
}
