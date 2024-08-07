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

int N, M;


int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

char board[1001][1001];
bool visited[1001][1001];

bool canGo;

// 현재 위치에서 N, M 까지 가는 최단 경로를 반환한다.
int play(int y, int x, bool power) {

    if (y == N && x == M) {
        canGo = true;
        return 1;
    }

    int ret = 1000000000;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
        // 다음 위치를 방문했었다면
        if (visited[ny][nx]) continue;
        // 다음 위치가 장애물일때
        if (board[ny][nx] == '1') {
            if (!power) {
                visited[ny][nx] = true;
                ret = min(ret, play(ny, nx, true) + 1);
                visited[ny][nx] = false;
            }
            continue;
        }
        visited[ny][nx] = true;
        ret = min(ret, play(ny, nx, power) + 1);
        visited[ny][nx] = false;
    }


    return ret;
}


void p_2206() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> board[i][j];
        }
    }

    if (N == 1 && M == 1) {
        cout << 1;
        return;
    }

    visited[1][1] = true;
    int ret = play(1, 1, false);
    if (!canGo) {
        cout << -1;
    } else {
        cout << ret;
    }
}
