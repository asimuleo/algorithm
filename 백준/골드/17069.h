//
// Created by SSAFY on 24. 9. 3.
//

#include <iostream>
#include <cstring>
using namespace std;

int N;
int board[32][32];
long long cache[3][32][32];


long long play(int state, int y, int x) {
    if (y == N - 1 && x == N - 1) {
        return 1;
    }

    long long &ret = cache[state][y][x];
    if (ret != -1) {
        return ret;
    }
    ret = 0;

    switch (state) {
        case 0:
            if (x + 1 < N
                && board[y][x + 1] == 0) {
                ret += play(0, y, x + 1);
            }
            if (
                x + 1 < N && y + 1 < N
                && board[y][x + 1] == 0
                && board[y + 1][x] == 0
                && board[y + 1][x + 1] == 0) {
                ret += play(1, y + 1, x + 1);
            }
            break;
        case 1:
            if (x + 1 < N
                && board[y][x + 1] == 0) {
                ret += play(0, y, x + 1);
            }
            if (y + 1 < N
                && board[y + 1][x] == 0) {
                ret += play(2, y + 1, x);
            }
            if (x + 1 < N && y + 1 < N
                && board[y][x + 1] == 0
                && board[y + 1][x] == 0
                && board[y + 1][x + 1] == 0) {
                ret += play(1, y + 1, x + 1);
            }
            break;
        case 2:
            if (y + 1 < N
                && board[y + 1][x] == 0) {
                ret += play(2, y + 1, x);
            }
            if (x + 1 < N && y + 1 < N
                && board[y][x + 1] == 0
                && board[y + 1][x] == 0
                && board[y + 1][x + 1] == 0) {
                ret += play(1, y + 1, x + 1);
            }
            break;
    }


    return ret;
}

int p_17069() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    memset(cache, -1, sizeof(cache));

    cout << play(0, 0, 1);
    return 0;
}
