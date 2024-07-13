//
// Created by cs.javah on 2024. 7. 13.
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

void printV(vector<vector<int>> &board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void printWall(vector<pair<int, int>> &wall) {
    for (int i = 0; i < wall.size(); i++) {
        cout << wall[i].first << ',' << wall[i].second << ' ';
    }
    cout << endl;
}

// 특정위치 주변에 아무것도 없는 경우네는 넣지를 말자.
// 4방위 를 조사하면서 모두 0이면 false 이다.
bool go(vector<vector<int>> &board, int i, int j) {
    for (int k = 0; k < 8; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N) return true;
        if (board[ny][nx] != 0) return true;

    }

    return false;
}


// 주어진 board 에 대하여 안전영역이 최대크기를 출력한다.
int safe(vector<vector<int>> &board) {
//    printV(board);
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) ret++;
        }
    }
    return ret;
}

// 주어진 board 에 대하여 바이러스 침범을 가정해서, 안전영역이 최대크기를 출력.
int virus(vector<vector<int>> board) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 2) {

                // bfs
                queue<pair<int, int>> q;
                q.push({i, j});
                board[i][j] = 3;

                while (q.size()) {

                    pair<int, int> u = q.front();
                    q.pop();
                    board[u.first][u.second] = 3;

                    for (int k = 0; k < 4; k++) {
                        int ny = u.first + dy[k];
                        int nx = u.second + dx[k];

                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                        if (board[ny][nx] != 0) continue;
                        q.push({ny, nx});
                    }


                }


            }
        }
    }

    return safe(board);
}

// 주어진 board 에 대하여 가능한 모든 경우에 대한 안전 영역의 최대값을 구한다.
int play(vector<vector<int>> &board, vector<pair<int, int>> &wall, int step) {

    if (step == 3) {
        // 바이러스 실행!!!!
//        printWall(wall);
        return virus(board);
    }

    int ret = 0;

    int i = wall[step - 1].first;
    int j = wall[step - 1].second + 1;

    if (j == M) {
        j = 0;
        i++;
    }

    while(i != N && j != M) {

        if (board[i][j] == 0 && go(board, i, j)) {
            wall.push_back({i, j});
            board[i][j] = 1;
            ret = max(ret, play(board, wall, step + 1));
            board[i][j] = 0;
            wall.pop_back();
        }

        j++;
        if (j == M) {
            j = 0;
            i++;
        }

    }

    return ret;

}


/**

*/
void p_14502() {

    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    vector<pair<int, int>> wall;

    int ret = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0 && go(board, i, j)) {
                wall.push_back({i, j});
                board[i][j] = 1;
                ret = max(ret, play(board, wall, 1));
                board[i][j] = 0;
                wall.pop_back();
            }
        }
    }


    cout << ret;


}