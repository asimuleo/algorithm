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

int visited[200001]; // 방문 처리를 위한 배열
int command[200001]; // 역 추적

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

void bfs() {
    memset(visited, -1, sizeof(visited));
    memset(command, -1, sizeof(command));

    queue<int> q;
    q.push(N);
    visited[N] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < 3; ++i) {
            int v = way(i, u);

            if (v == K) {
                // 도달 했다면
                command[v] = u;
                visited[v] = visited[u] + 1;
                return;
            }

            if (v < 0 || v > 200000) continue; // 범위를 벗어난다면 제외
            if (visited[v] != -1) continue; // 방문 했다면 제외

            q.push(v);
            visited[v] = visited[u] + 1;
            command[v] = u; // 과거 트래킹
        }
    }
}


void p_13913() {
    cin >> N >> K;

    if (N == K) {
        cout << 0 << '\n' << N;
        return;
    }


    bfs();

    cout << visited[K] << endl;

    // 트래킹
    vector<int> result;

    int i = K;
    while (true) {
        if (N == i) {
            break;
        }
        result.push_back(i);
        i = command[i];
    }


    reverse(result.begin(), result.end());
    cout << N << ' ';
    for (int r: result) {
        cout << r << ' ';
    }
}
