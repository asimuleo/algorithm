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

int bfs_visited[100001];
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
    memset(bfs_visited, -1, sizeof(bfs_visited));

    queue<int> q;
    q.push(N);
    bfs_visited[N] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < 3; ++i) {
            int v = way(i, u);
            if (v < 0 || v > 100000) continue; // 범위를 벗어난다면 제외
            if (bfs_visited[v] != -1) continue; // 방문했다면 제외
            if (v == K) {
                return bfs_visited[u] + 1;
            }
            bfs_visited[v] = bfs_visited[u] + 1;
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

    if (bfs_visited[position] == -1) return 0; // bfs 로 방문 안한 곳은 제외시킨다.


    // 만약 아무리 step 만큼 진행시켜도 도달하지 못할 것이라면 제외시킨다.
    if (ret_time - step < 17 && (position + 1) * pow(2, ret_time - step) < K)
        return 0;

    // 솔직히 -1을 N보다 작은 방향으로 2번 하는건 아닌 것 같은데...
    if (position < N - 1)
        return 0;

    // 곱하기 횟수도 제한할 수 있지 않을까?



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

    if (N > K) {
        cout << N - K << '\n' << 1;
        return;
    }

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

    // dfs 를 bfs 로 방문한 곳만 하면 시간을 획기적으로 줄일 수 있지 않을까?
    ret_cnt = dfs(N, 0);
    cout << ret_cnt;
}
