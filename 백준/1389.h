//
// Created by cs.javah on 2024. 7. 17.
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

using namespace std;

int N, M;

// from 에서 to 까지의 거리를 구한 후에 distance 에 반영한다.
void bfs(vector<vector<int> > &distance, int from, int to) {
    vector<int> visited(N, -1);

    queue<int> q;

    q.push(from);
    visited[from] = 0;

    while (q.size()) {
        // 일단 뽑는다.
        int u = q.front();
        q.pop();

        // 모든 후보에 대해 큐에 넣는다.
        for (int v = 0; v < N; v++) {
            // 연결 된 친구만!
            if (distance[u][v] != 1) continue;
            // 이미 방문한것은 제외
            if (visited[v] >= 0) continue;

            q.push(v);
            visited[v] = visited[u] + 1;

            if (v == to) {
                distance[from][to] = visited[v];
                distance[to][from] = visited[v];
                return;
            }
        }
    }
}


void p_1389() {
    cin >> N >> M;

    vector<vector<int> > distance(N, vector<int>(N, 0));

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        distance[a][b] = 1;
        distance[b][a] = 1;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            bfs(distance, i, j);
        }
    }

    int ret = 1000000000;
    int ret_index = -1;

    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += distance[i][j];
        }
        if (ret > sum) {
            ret = sum;
            ret_index = i;
        }
    }

    cout << ret_index + 1;
}
