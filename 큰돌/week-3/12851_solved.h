//
// Created by 임혁 on 24. 7. 21.
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
#include <sstream>
#include <cstring>

using namespace std;

int N, K;
int visited[200001];

// v를반환
int way(int w, int u) {
    switch (w) {
        case 0:
            return u - 1;
        case 1:
            return u + 1;
        case 2:
            return u * 2;
    }
}

void p_12851_3() {
    cin >> N >> K;

    memset(visited, false, sizeof(visited));

    queue<pair<int, int> > q;
    q.emplace(N, 0);
    visited[N] = 0;

    if (N == K) {
        cout << 0 << '\n' << 1;
        return;
    }

    vector<pair<int, int> > result;


    while (!q.empty()) {
        // 현재위치, 최단거리,
        pair<int, int> u = q.front();
        q.pop();

        for (int i = 0; i < 3; ++i) {
            int v = way(i, u.first);
            if (v < 0 || v > 200000) continue; // 범위를 벗어난다면 제외


/**
* 내가 알아낸 진짜 신의
*/

            if (visited[v] <= 3) { // 중요
                if (v == K) {
                    if (result.empty()) {
                        result.emplace_back(v, u.second + 1);
                    } else if (result[0].second == u.second + 1) {
                        result.emplace_back(v, u.second + 1);
                    }
                }
                visited[v]++;
                q.emplace(v, u.second + 1);
            }
        }

        // if (ret_time != -1 && visited[u] > ret_time) break;
    }

    cout << result[0].second << endl;
    cout << result.size();
}
