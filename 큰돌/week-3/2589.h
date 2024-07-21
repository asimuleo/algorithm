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

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int N, M; // 세로, 가로

vector<vector<bool> > board; // 지도
int visited[50][50];

//int distance[50][50]; // 두 Land 의 거리

// 현재 위치에 대하여 가장 먼 거리를 구한다.
int play(int y, int x) {

    int ret = 0;

    queue<pair<int, int> > q;
    q.push({y, x});
    visited[y][x] = 0;
    while (q.size()) {
        int uy, ux;
        tie(uy, ux) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = uy + dy[i];
            int nx = ux + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (!board[ny][nx]) continue; // 육지만 가능
            if (visited[ny][nx] != -1) continue; // 방문 한적 없어야 가능
            visited[ny][nx] = visited[uy][ux] + 1;
            q.push({ny, nx});
        }
        ret = max(ret, visited[uy][ux]);
    }

    return ret;

}

void p_2589() {

    cin >> N >> M;
    board = vector<vector<bool> >(N, vector<bool>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            board[i][j] = c == 'L';
        }
    }


    int ret = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j]) {
                memset(visited, -1, sizeof(visited));
                ret = max(ret, play(i, j));
            }
        }
    }

    cout << ret;

}