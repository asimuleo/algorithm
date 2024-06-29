//
// Created by csjav on 24. 6. 29.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;




// 지뢰 찾기를 하는 표의 크기가 N*N
int n;

void printBoard(vector<vector<bool> > &visited) {
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          cout << (visited[i][j] ? '_' : 'X');
        }
        cout << endl;
    }
}

// 8방위
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// 주위에도 지뢰가 하나도 없으면 true
bool isZero(vector<vector<bool> > &board, int y, int x) {
    for (int i = 0; i < 8; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 경기장을 벗어났을떄
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (board[ny][nx]) return false;
    }

    return true;
}


// zero 로 부터 전방위의 또다른 zero 모두 open 한다.
void open(vector<vector<bool> > &board, vector<vector<bool> > &visited, int y, int x) {
    if (visited[y][x]) return;
    visited[y][x] = true;

    for (int i = 0; i < 8; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 경기장을 벗어났을떄
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        if (!visited[ny][nx] && !board[ny][nx] && isZero(board, ny, nx)) {
            open(board, visited, ny, nx);
        }
        visited[ny][nx] = true; // 이것때문에 시간 오래 걸림 ********************
    }
}


/**
 * 지뢰 찾기를 하는 표의 크기가 N*N
 * ‘*’이면 지뢰가 있다는 뜻이고, ‘.’이면 지뢰가 없다는 뜻이다.
 */
void 파핑파핑지뢰찾기() {
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> n;
        vector<vector<bool> > board; // 게임판
        vector<vector<bool> > visited; // 게임판
        for (int i = 0; i < n; ++i) {
            board.emplace_back();
            visited.emplace_back();
            for (int j = 0; j < n; ++j) {
                char c;
                cin >> c;
                board[i].push_back(c == '*');
                visited[i].push_back(c == '*');
            }
        }

        int ret = 0;

        // 모든 칸에 대하여
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!board[i][j] && // 해당 칸이 지뢰가 아닌데
                    !visited[i][j] && // open 된 적이 없고,
                    isZero(board, i, j) // 주위에도 지뢰가 하나도 없으면
                ) {
                    // 오픈 시작
                    open(board, visited, i, j);
                    ret++;
                }
            }
        }

        // printBoard(visited);

        // 모든 칸에 대하여
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) ret++;
            }
        }

        cout << '#' << test_case << ' ' << ret << endl;
    }
}
