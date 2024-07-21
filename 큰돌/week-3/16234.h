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

int N, L, R;

vector<vector<int> > board; // 인구수
bool visited[50][50];

// 주어진 위치에 대해 연합이 발생하는지의 여부를 반환한다.
bool play(int y, int x) {

    if (visited[y][x]) return false;

    vector<pair<int, int> > country;  // 연합
    int people_size = 0; // 연합의 인구수


    // 구하기
    queue<pair<int, int> > q;
    people_size += board[y][x];
    q.emplace(y, x);
    country.emplace_back(y, x);
    visited[y][x] = true;
    while (!q.empty()) {
        int uy, ux;
        tie(uy, ux) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = uy + dy[i];
            int nx = ux + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (visited[ny][nx]) continue; // 방문 한적 없어야 가능
            int dis = abs(board[uy][ux] - board[ny][nx]);
            if (dis < L || dis > R) continue; // 인구 차이 [L,R] 이여야 가능
            visited[ny][nx] = true;
            people_size += board[ny][nx];
            q.emplace(ny, nx);
            country.emplace_back(ny, nx);
        }
    }

    if (country.size() == 1) return false;

    // 인구 이동
    for (int i = 0; i < country.size(); ++i) {
        int cy, cx;
        tie(cy, cx) = country[i];
        board[cy][cx] = people_size / country.size();
    }

    return true;

}

void p_16234() {

    cin >> N >> L >> R;

    board = vector<vector<int> >(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }


    int ret = -1;

    bool keep_go = true;
    while (keep_go) {
        keep_go = false;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                bool b = play(i, j);
                if (b) keep_go = true;
            }
        }

        ret++; // 하루 추가
    }

    cout << ret;


}
