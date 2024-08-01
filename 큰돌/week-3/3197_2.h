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

// 왼쪽 백조
int lby, lbx;

// 오른쪽 백조
int rby, rbx;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};


struct point {
    int y;
    int x;
};

vector<vector<point> > white_boundary_list;
vector<point> left_boundary;
vector<point> right_boundary;

void tenkai(char c, int sy, int sx, vector<point> &boundary) {
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
            if (board[ny][nx] == 'X') {
                boundary.push_back({ny, nx});
                continue;
            }
            if (board[ny][nx] == c) continue;

            board[ny][nx] = c;
            q.emplace(ny, nx);
        }
    }
}

// r 과 l 이 만나면 false 반환.
bool melt() {
    // 영역 넓히기

    // 화이트 영역 넓히기
    for (auto &white_boundary: white_boundary_list) {
        bool left = false, right = false;
        vector<point> temp;
        for (auto p: white_boundary) {
            for (int i = 0; i < 4; ++i) {
                int ny = p.y + dy[i];
                int nx = p.x + dx[i];
                if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
                if (board[ny][nx] == 'w') continue;
                if (board[ny][nx] == 'r') right = true;
                else if (board[ny][nx] == 'l') left = true;
                board[ny][nx] = 'w';
                temp.push_back({ny, nx});
            }
        }
        // 만약 왼쪽이나 오른쪽을 만났다면 편입.
        if (left) {
            left_boundary.insert(left_boundary.end(),
                                 white_boundary.begin(), white_boundary.end());
            white_boundary.clear();
        } else if (right) {
            right_boundary.insert(right_boundary.end(),
                                  white_boundary.begin(), white_boundary.end());
            white_boundary.clear();
        } else {
            white_boundary = temp;
        }
    }

    // 왼쪽 백조 넓히기
    vector<point> temp;
    for (auto p: left_boundary) {
        for (int i = 0; i < 4; ++i) {
            int ny = p.y + dy[i];
            int nx = p.x + dx[i];
            if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
            if (board[ny][nx] == 'l') continue;
            if (board[ny][nx] == 'r') return false;
            board[ny][nx] = 'l';
            temp.push_back({ny, nx});
        }
    }
    left_boundary = temp;
    temp.clear();

    // 오른쪽 백조 넓히기
    for (auto p: right_boundary) {
        for (int i = 0; i < 4; ++i) {
            int ny = p.y + dy[i];
            int nx = p.x + dx[i];
            if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
            if (board[ny][nx] == 'r') continue;
            if (board[ny][nx] == 'l') return false;
            board[ny][nx] = 'r';
            temp.push_back({ny, nx});
        }
    }
    right_boundary = temp;

    return true;
}

void p_3197_2() {
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
    tenkai('l', lby, lbx, left_boundary);

    if (board[rby][rbx] == 'l') {
        cout << 0;
        return;
    }

    // 오른쪽 백조 영역 전개
    tenkai('r', rby, rbx, right_boundary);

    // 녹이기 영역 전개
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (board[i][j] == '.') {
                vector<point> white;
                white_boundary_list.push_back(white);
                tenkai('w', i, j, white);
            }
        }
    }


    int ret = 0;

    while (melt()) {
        ret++;
    }

    cout << ret;
}
