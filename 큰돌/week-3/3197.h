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

bool first = true;

vector<pair<int, int>> melted_list;

// 만약 L 을 만나면 true 반환
bool tenkai(char c, int sy, int sx) {
    queue<pair<int, int> > q;
    q.emplace(sy, sx);
    board[sy][sx] = c;

    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
            if (board[ny][nx] == 'L') {
                // 백조 만났다!!!
                return true;
            }
            if (board[ny][nx] == 'X') {
                board[ny][nx] = 'O';
                continue;
            }
            if (board[ny][nx] == 'O') continue;
            if (board[ny][nx] == c) continue;

            board[ny][nx] = c;
            q.emplace(ny, nx);
        }
    }
    return false;
}

void melt(char way, int y, int x) {
    if (board[y][x] == 'O') {
        for (int k = 0; k < 4; ++k) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
            if (board[ny][nx] == 'X') {
                board[ny][nx] = 'K';
            }
        }
        board[y][x] = way;
    }
}

/**
 * 첫 melt 후 O 표시된 곳의 상하좌우만
 */
void smart_melt() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            melt('l', i, j);
            melt('r', i, j);
            melt('w', i, j);
        }
    }

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (board[i][j] == 'K')
                board[i][j] = 'O';
        }
    }
}

/**
 *
 * @return 백조가 만나면 TRUE!
 */
bool meet() {
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

    // 왼쪽 백조 영역 전개
    if (tenkai('l', lby, lbx)) {
        cout << 0;
    } else {
        // 오른쪽 백조 영역 전개
        tenkai('r', rby, rbx);

        int ret = 0;

        // 녹이기 영역 전개
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                if (board[i][j] == '.') {
                    tenkai('w', i, j);
                }
            }
        }


        while (!meet()) {
            // 백조가 만날 수 있나?

            // . 을 발견하면 녹이기
            if (!first) smart_melt();
            else {
                memset(visited, false, sizeof(visited));
                for (int i = 1; i <= R; ++i) {
                    for (int j = 1; j <= C; ++j) {
                        if (board[i][j] == '.' && !visited[i][j]) {
                            melt(i, j);
                        }
                    }
                }
                first = false;
            }

            ret++;
        }

        cout << ret;
    }
}
