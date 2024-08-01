//
// Created by cs.javah on 2024. 8. 1.
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

// 세로 가로
int R, C;

// 백조의 호수
char board[1501][1501];

bool visited[1501][1501];

// 왼쪽 백조
int lby, lbx;

// 오른쪽 백조
int rby, rbx;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

vector<pair<int, int> > boundary;

void melt() {
    vector<pair<int, int> > temp;
    for (auto it: boundary) {
        for (int i = 0; i < 4; ++i) {
            int ny = it.first + dy[i];
            int nx = it.second + dx[i];
            if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
            if (board[ny][nx] == 'O') continue;
            if (board[ny][nx] == 'X') {
                temp.emplace_back(ny, nx);
                board[ny][nx] = 'O';
            }
        }
        board[it.first][it.second] = '.';
    }
    boundary = temp;
}

void first_melt(int y, int x) {
    visited[y][x] = true;

    if (board[y][x] == 'X') {
        board[y][x] = 'O';
        boundary.emplace_back(y, x);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
        if (board[ny][nx] == 'O') continue;
        if (visited[ny][nx]) continue;
        first_melt(ny, nx);
    }
}


/**
 *
 * @return 백조가 만나면 TRUE!
 */
bool meet() {
    memset(visited, false, sizeof(visited));

    queue<pair<int, int> > q;
    q.emplace(lby, lbx);
    visited[lby][lbx] = true;

    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
            if (nx == rbx && ny == rby) {
                // 백조 만났다!!!
                return true;
            }
            if (board[ny][nx] == 'X') continue; // 물만 이동 가능
            if (visited[ny][nx]) continue;

            visited[ny][nx] = true;
            q.emplace(ny, nx);
        }
    }

    return false;
}


void p_3197() {
    cin >> R >> C;

    bool left = true;

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'L') {
                if (left) {
                    lby = i;
                    lbx = j;
                    left = false;
                } else {
                    rby = i;
                    rbx = j;
                }
            }
        }
    }

    bool first = true;

    int ret = 0;

    while (!meet()) {
        // 백조가 만날 수 있나?
        memset(visited, false, sizeof(visited));

        if (first) {
            // . 을 발견하면 녹이기
            for (int i = 1; i <= R; ++i) {
                for (int j = 1; j <= C; ++j) {
                    if (board[i][j] == '.') {
                        first_melt(i, j);
                    }
                }
            }
            first = false;
        } else {
            melt();
        }

        ret++;
    }

    cout << ret;
}
