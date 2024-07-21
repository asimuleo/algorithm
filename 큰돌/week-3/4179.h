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

char board[1000][1000];
int visited[1000][1000];
int fired[1000][1000];

int R, C;

// 지훈이 탈출!
void play(int y, int x) {

    queue<pair<int, int> > q;
    q.emplace(y, x);
    visited[y][x] = 0;
    while (!q.empty()) {
        int uy, ux;
        tie(uy, ux) = q.front();
        q.pop();
        if (uy == 0 || uy == R - 1 || ux == 0 || ux == C - 1) {
            // 탈출!!
            cout << visited[uy][ux] + 1;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int ny = uy + dy[i];
            int nx = ux + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (board[ny][nx] != '.') continue; // 이동 가능한 곳이 아니면 불가
            if (visited[ny][nx] != -1) continue; // 방문 한적이 있으면 불가
            // 불이 날 예정이 없고, 불이 나는 시간이 내가 갈 시간보다 클 떄만 가능
            if (fired[ny][nx] != -1 && fired[ny][nx] > visited[uy][ux] + 1) {
                visited[ny][nx] = visited[uy][ux] + 1;
                q.emplace(ny, nx);
            }
        }
    }

    cout << "IMPOSSIBLE";

}

// 현재 위치에 대해 불을 지른다!
// 아마도 1000*1000 걸린다.
void fire(int y, int x) {

    queue<pair<int, int> > q;
    q.emplace(y, x);
    fired[y][x] = 0;
    while (!q.empty()) {
        int uy, ux;
        tie(uy, ux) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = uy + dy[i];
            int nx = ux + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (board[ny][nx] == '#') continue; // 벽이면 불가
            if (fired[ny][nx] <= fired[uy][ux] + 1) continue; // 이미 더 빨리 불이 일어난 적이 있으면 불가
            fired[ny][nx] = fired[uy][ux] + 1;
            q.emplace(ny, nx);
        }
    }

}

void p_4179() {

    cin >> R >> C;

    int jy, jx, fy, fx;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'J') {
                jy = i;
                jx = j;
            }
        }
    }


    // fired 구하기
    fill(&fired[0][0], &fired[999][999], 1000000000);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (board[i][j] == 'F') {
                fire(i, j);
            }
        }
    }


    memset(visited, -1, sizeof(visited));
    play(jy, jx);


}

//4 7
//#######
//#J.#.FF
//##..##F
//###....