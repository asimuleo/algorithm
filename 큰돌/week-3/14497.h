//
// Created by cs.javah on 2024. 7. 28.
//

#include <cstdio>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

// 주난이가 위치한 교실의 크기 N, M
int N, M;

// 주난이의 위치 1 ~
int jx, jy;

// 범인(hyuk)의 위치 1 ~
int hx, hy;

// 교실
char board[301][301];
bool visited[301][301];

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};


/**
 * 주난이가 한번 점프한다.
 * @return 범인을 발견하면 TRUE
 */
void play(int y, int x) {
    visited[y][x] = true;
    if (board[y][x] == '1' || board[y][x] == '#') {
        board[y][x] = '4';
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
        if (visited[ny][nx]) continue;
        if (board[ny][nx] == '4') continue;
        play(ny, nx);
    }
}

bool killed() {
    return board[hy][hx] != '#';
}

/**
 * 주난이의 파동을 맞은 친구들을 쓰러트린다.
 */
void attack() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (board[i][j] == '4')
                board[i][j] = '0';
        }
    }
}


/**
 * 파동은 친구들을 쓰러트릴 때 까지 퍼진다.
 * 즉. 범위를 벗어나거나 친구를 만나기 전까지는 계속해서 4방향을 탐색한다.
 */
void p_14497() {
    cin >> N >> M;
    cin >> jy >> jx >> hy >> hx;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> board[i][j];
        }
    }

    int ret = 0;

    while (!killed()) {
        memset(visited, false, sizeof(visited));
        // 범인을 찾을때 까지 반복
        play(jy, jx);
        attack();
        ret++;
    }

    cout << ret;
}
