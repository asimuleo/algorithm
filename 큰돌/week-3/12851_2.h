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

void p_12851_2() {
    cin >> N >> K;

    vector<int> visited(100001, -1);

    queue<pair<int, vector<int> > > q;
    visited[N] = 0;
    q.emplace(N, visited);

    int ret_time = -1;
    int ret_way_cnt = 0;

    while (!q.empty()) {
        pair<int, vector<int> > u = q.front();
        q.pop();


        for (int i = 0; i < 3; ++i) {
            int v = way(i, u.first);
            if (v < 0 || v > 100000) continue; // 범위를 벗어난다면 제외
            if (u.second[v] != -1) continue; // 방문했다면 제외

            // if (ret_time != -1 && visited[u] > ret_time) break;
            if (v == K) {
                if (ret_time == -1)
                    ret_time = u.second[u.first] + 1;
                if (u.second[u.first] + 1 == ret_time)
                    ret_way_cnt++;
                continue;
            }

            vector<int> v_visited = u.second;
            v_visited[v] = u.second[u.first] + 1;
            q.emplace(v, v_visited); // 새로운 경로를 갈 때마다 자신만의 방문점을 전송
        }

        if (ret_time != -1 && u.second[u.first] > ret_time) break;
    }

    cout << ret_time << endl;
    cout << ret_way_cnt;
}
