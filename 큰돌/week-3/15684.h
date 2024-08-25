//
// Created by 임혁 on 24. 8. 25.
//

#include "iostream"

using namespace std;

int N, M, H;
int board[11][31];
int max_size;

// i 번째 사다리가 i 번재에 도착해야한다.
bool play() {

    for (int i = 1; i <= N; ++i) {
        int start = i;
        int h = 1;
        while (h <= H) {
            if (board[start][h] == 1) start++;
            else if (start > 1 && board[start - 1][h] == 1) start--;
            h++;
        }
        if (start != i) return false;
    }
    return true;
}

bool check(int size, int start) {

    if (size == max_size) {
        return play();
    }

    for (int i = start / H + 1; i < N; ++i) {
        for (int j = start % H + 1; j <= H; ++j, ++start) {
            if (board[i][j] == 1) continue;
            if (i > 1 && board[i - 1][j] == 1) continue;
            if (i < N - 1 && board[i + 1][j] == 1) continue;
            board[i][j] = 1;
            if (check(size + 1, start)) return true;
            board[i][j] = 0;
        }
    }

    return false;

}


int p_15684() {
    cin >> N >> M >> H;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        board[b][a] = 1;
    }

    if (play()) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= 3; ++i) {
        max_size = i;
        bool possible = check(0, 0);
        if (!possible) continue;
        cout << i;
        return 0;
    }

    cout << -1;

}