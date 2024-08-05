//
// Created by cs.javah on 2024. 8. 5.
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

struct point {
    int y;
    int x;
};

// 세로 가로
int R, C;

// 백조의 호수
char board[1501][1501];

bool visited[1501][1501];
bool ice_visited[1501][1501];

// 왼쪽 백조
int lby, lbx;

// 오른쪽 백조
int rby, rbx;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void print_board() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

void p_3197() {
    cin >> R >> C;

    bool left = true;

    queue<point> ice; // 얼음 큐
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
            if (board[i][j] != 'X') {
                ice.push({i, j});
                ice_visited[i][j] = true;
            }
        }
    }

    // 두 백조의 위치가 같을 경우
    if (rby == 0) {
        cout << 0;
        return;
    }

    int cnt = 0;

    queue<point> q; // 백조 큐
    q.push({lby, lbx});
    visited[lby][lbx] = true;


    // 백조를 만날 때 까지 진행한다.
    while (true) {

        // 1. 백조를 만났는가?
        // 특정 한 백조로 부터 다른 백조를 만날 때 까지 dfs 를 돌렸는가.
        // X 를 만나면 다음턴에 진행 할 것이기 때문에. x 들의 위치는 q 에 저장
        queue<point> temp;
        while (!q.empty()) {
            point p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = p.y + dy[i];
                int nx = p.x + dx[i];
                if (ny < 1 || ny > R || nx < 1 || nx > C || visited[ny][nx]) continue;
                visited[ny][nx] = true;
                if (ny == rby && nx == rbx) {
                    // 백조 만나며 끝
                    cout << cnt;
                    return;
                }
                if (board[ny][nx] == 'X') {
                    board[ny][nx] = '.';
                    temp.push({ny, nx}); // 너는 다음 턴이야
                } else q.push({ny, nx}); // 너는 지금 해야지
            }
        }
        q = temp;

        // 2. 얼음을 녹인다.
        // 얼음 큐가 비어 있다면 전체 반복문으로 돈다. x를 만나면 얼음큐에 넣는다.
        // 얼음 큐가 비어 있지 않다면, 해당 얼음큐의 사이즈 만큼 얼음큐에서 팝해서 넣는다.
        queue<point> ice_temp;
        while (!ice.empty()) {
            point p = ice.front();
            ice.pop();
            if (visited[p.y][p.x])
                continue;
            for (int i = 0; i < 4; i++) {
                int ny = p.y + dy[i];
                int nx = p.x + dx[i];
                if (ny < 1 || ny > R || nx < 1 || nx > C || ice_visited[ny][nx]) continue;
                ice_visited[ny][nx] = true;
                if (board[ny][nx] == 'X') {
                    board[ny][nx] = '.';
                    ice_temp.push({ny, nx}); // 너는 다음 턴이야
                } else ice.push({ny, nx}); // 너는 지금 해야지
            }
        }
        ice = ice_temp;


        // 얼음을 녹였다는 것 자체가 한 시간이 지났다는 뜻이다.
        cnt++;
    }
}
