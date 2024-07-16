//
// Created by 임혁 on 24. 7. 16.
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

int R, C, T;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void test_printB(const vector<vector<int> > &board) {
    int ret = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}


void printB(const vector<vector<int> > &board) {
    int ret = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            ret += board[i][j];
        }
    }
    cout << ret + 2;
}

void clean_up(vector<vector<int> > &board, int y, int x) {

    vector<vector<int> > clean(R, vector<int>(C, 0));


    // 1
    for (int i = 2; i < C; ++i) {
        clean[y][i] = board[y][i - 1];
    }
    // 2
    for (int i = y - 1; i >= 0; --i) {
        clean[i][C - 1] = board[i + 1][C - 1];
    }
    // 3
    for (int i = C - 2; i >= 0; --i) {
        clean[0][i] = board[0][i + 1];
    }
    // 4
    for (int i = 1; i <= y - 1; ++i) {
        clean[i][0] = board[i - 1][0];
    }

    board[y][x + 1] = 0;

    // 1
    for (int i = 2; i < C; ++i) {
        board[y][i] = clean[y][i] ;
    }
    // 2
    for (int i = y - 1; i >= 0; --i) {
        board[i][C - 1] = clean[i][C - 1] ;
    }
    // 3
    for (int i = C - 2; i >= 0; --i) {
        board[0][i] = clean[0][i] ;
    }
    // 4
    for (int i = 1; i <= y - 1; ++i) {
        board[i][0] = clean[i][0] ;
    }

}

void clean_down(vector<vector<int> > &board, int y, int x) {

    vector<vector<int> > clean(R, vector<int>(C, 0));

    // 1
    for (int i = 2; i < C; ++i) {
        clean[y][i] = board[y][i - 1];
    }
    // 2
    for (int i = y + 1; i < R; ++i) {
        clean[i][C - 1] = board[i - 1][C - 1];
    }
    // 3
    for (int i = C - 2; i >= 0; --i) {
        clean[R - 1][i] = board[R - 1][i + 1];
    }
    // 4
    for (int i = R - 2; i >= y + 1; --i) {
        clean[i][0] = board[i + 1][0];
    }

    board[y][x + 1] = 0;

    // 1
    for (int i = 2; i < C; ++i) {
        board[y][i] = clean[y][i];
    }
    // 2
    for (int i = y + 1; i < R; ++i) {
        board[i][C - 1] = clean[i][C - 1];
    }
    // 3
    for (int i = C - 2; i >= 0; --i) {
        board[R - 1][i] = clean[R - 1][i];
    }
    // 4
    for (int i = R - 2; i >= y + 1; --i) {
        board[i][0] = clean[i][0];
    }

}


void mise(const vector<vector<int> > &board, vector<vector<int> > &mimi, int y, int x) {
    int mi = 0;
    int minus = board[y][x] / 5;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 범위벗어는 것은 제외
        if (ny >= R || ny < 0 || nx >= C || nx < 0) continue;
        mimi[ny][nx] += minus;
        if(board[ny][nx] != -1)
            mi++;
    }
    mimi[y][x] -= minus * mi;
}

void play(vector<vector<int> > &board) {
    // 확산용 board를 따로 준비해야한다.
    vector<vector<int> > mimi(R, vector<int>(C, 0));

    // 미세먼지확산
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (board[i][j] >= 5) {
                // 확산
                mise(board, mimi, i, j);
            }
        }
    }

    // 미세먼지 증감 적용
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if(board[i][j] != -1)
                board[i][j] += mimi[i][j];
        }
    }

    for (int j = 0; j < R; ++j) {
        if (board[j][0] == -1) {
            // 위쪽 청정기
            clean_up(board, j, 0);
            // 아래쪽 청정기
            clean_down(board, j+1, 0);
            break;
        }
    }
}

void p_17144() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> R >> C >> T;

    vector<vector<int> > board(R, vector<int>(C));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < T; ++i) {
        play(board);
    }

    printB(board);
}
