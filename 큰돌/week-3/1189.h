//
// Created by 임혁 on 24. 8. 25.
//

#include "iostream"

using namespace std;

int R, C, K;
char board[5][5];

int ret = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void play(int step, int y, int x) {
    if (step == K) {
        if (y == 0 && x == C - 1) ret++;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (board[ny][nx] == 'T') continue;
        board[ny][nx] = 'T';
        play(step + 1, ny, nx);
        board[ny][nx] = '.';
    }
}

int p_1189() {

    cin >> R >> C >> K;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> board[i][j];
        }
    }

    board[R - 1][0] = 'T';
    play(1, R - 1, 0);

    cout << ret;

}