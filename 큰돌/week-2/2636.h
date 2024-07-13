//
// Created by 임혁 on 24. 7. 13.
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

using namespace std;

int N, M;

int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};

bool is_end(vector<vector<int>> &board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] != 0) return false;
        }
    }
    return true;
}

int two_to_zero(vector<vector<int>> &board) {
    int deleted_cheese = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 2) {
                board[i][j] = 0;
                deleted_cheese++;
            }
        }
    }
    return deleted_cheese;
}

void search_zero(vector<vector<int>> &board) {

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    // bfs
    queue<pair<int, int>> q;

    // 공기 부터 시작
    // (0, 0~M-1) (0~N-1, M-1) (N-1, 0~M-1) (0~N-1, 0)
    for (int i = 0; i < M; ++i) {
        q.push({0, i});
        q.push({N - 1, i});
//        visited[0][i] = true;
//        visited[N-1][i] = true;
    }
    for (int i = 0; i < N; ++i) {
        q.push({i, 0});
        q.push({i, M - 1});
//        visited[i][0] = true;
//        visited[i][M-1] = true;
    }

    while (q.size()) {

        pair<int, int> u = q.front();
        q.pop();
        visited[u.first][u.second] = true;

        for (int k = 0; k < 4; k++) {
            int ny = u.first + dy[k];
            int nx = u.second + dx[k];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (visited[ny][nx]) continue;
            if (board[ny][nx] == 1) {
                board[ny][nx] = 2;
                continue;
            }
            if (board[ny][nx] != 0) continue;
            q.push({ny, nx});
        }

    }

}

void p_2636() {

    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    // 1. 0을 bfs 해서 만약 1을 만나면 2로 바꾼다
    // 2. 2를 0으로 바꾼다. 그리고 2의 개수를 저장해둔다. 그리고 시간을 더해준다.
    // 3. 만약 모든 칸이 0이라면 출력하고 종료한다.
    // 위에서 부터 다시 한다.

    int time = 0;
    int deleted_cheese = 0;


    while (true) {

        // 1
        search_zero(board);

        // 2
        deleted_cheese = two_to_zero(board);
        time++;

        // 3
        if (is_end(board)) {
            cout << time << '\n' << deleted_cheese;
            break;
        }

    }


}


