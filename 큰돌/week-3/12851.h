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

int ret_time;
int ret_cnt;

bool visited2[100001];

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

int bfs() {
    int visited[100001];
    memset(visited, -1, sizeof(visited));

    queue<int> q;
    q.push(N);
    visited[N] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < 3; ++i) {
            int v = way(i, u);
            if (v < 0 || v > 100000) continue; // 범위를 벗어난다면 제외
            if (visited[v] != -1) continue; // 방문했다면 제외
            if (v == K) {
                return visited[u] + 1;
            }
            visited[v] = visited[u] + 1;
            q.push(v);
        }
    }

    // 도달 할 리 없는 곳
    return -1;
}


int dfs(int position, int step) {

    if (step == ret_time) {
        if (position == K)
            return 1;
        return 0;
    }

    int sum = 0;

    for (int i = 0; i < 3; ++i) {
        int v = way(i, position);
        if (v < 0 || v > 100000) continue; // 범위를 벗어난다면 제외
        if (visited2[v]) continue; // 방문했다면 제외
        visited2[v] = true;
        sum += dfs(v, step + 1);
        visited2[v] = false;
    }

    return sum;

}

void p_12851() {

    cin >> N >> K;

    if (N == K) {
        cout << 0 << '\n' << 0;
        return;
    }


    /**
     * 가장 빠른 시간이 몇 초인 지는 bfs로 구하자.
     * 그리고 가장 빠른 시간으로 찾는 방법이 몇개인지는 dfs 로 구하는 거다.
     */
    ret_time = bfs();
    cout << ret_time << endl;

    memset(visited2, false, sizeof(visited2));
    visited2[N] = true;
    ret_cnt = dfs(N, 0);
    cout << ret_cnt;


}
