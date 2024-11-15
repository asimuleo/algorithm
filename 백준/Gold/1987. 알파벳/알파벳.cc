//
// Created by 임혁 on 24. 8. 05.
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

int R, C;

int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};


char board[21][21];
bool visited[21][21];
bool alpabet['Z' - 'A' + 1];


// 주어진 현재 위치와 방문 기록 에서 갈 수 있는 최대 거리를 반환한다.
int dfs(int y, int x) {
    int ret = 0;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 1 || nx > C || ny < 1 || ny > R || visited[ny][nx] || alpabet[board[ny][nx] - 'A']) continue;

        visited[ny][nx] = true;
        alpabet[board[ny][nx] - 'A'] = true;
        ret = max(ret, dfs(ny, nx) + 1);
        visited[ny][nx] = false;
        alpabet[board[ny][nx] - 'A'] = false;
    }

    return ret;
}


int main() {
    cin >> R >> C;

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> board[i][j];
        }
    }

    visited[1][1] = true;
    alpabet[board[1][1] - 'A'] = true;
    cout << dfs(1, 1) + 1;
}
