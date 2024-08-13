//
// Created by 임혁 on 24. 8. 07.
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

struct point {
    int y;
    int x;
    bool power; // true = 벽을 부술 힘이 있다.
};

int N, M;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

char board[1005][1005];
int visited[1005][1005][2];

void p_2206() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> board[i][j];
        }
    }

    memset(visited, -1, sizeof(visited));

    queue<point> q;
    q.push({1, 1, true});
    visited[1][1][1] = 1;

    while (!q.empty()) {
        const point p = q.front();
        q.pop();

        if (p.y == N && p.x == M) {
            cout << visited[p.y][p.x][p.power];
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (ny < 1 || ny > N || nx < 1 || nx > M) continue;

            if (board[ny][nx] == '1') {
                if (p.power && visited[ny][nx][0] == -1) {
                    // 힘을 사용
                    q.push({ny, nx, false});
                    visited[ny][nx][0] = visited[p.y][p.x][p.power] + 1;
                }
                continue;
            }

            if (visited[ny][nx][p.power] != -1) continue;
            q.push({ny, nx, p.power});
            visited[ny][nx][p.power] = visited[p.y][p.x][p.power] + 1;
        }
    }

    cout << -1;
}
