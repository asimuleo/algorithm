//
// Created by SSAFY on 24. 9. 5.
//

#include <iostream>
#include <vector>
using namespace std;

struct shark {
    int y;
    int x;
    int speed;
    int direction;
    int size;
};

// 낚시왕이 잡은 상어 크기의 합을 출력한다.
int p_17143() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int R, C, M;
    cin >> R >> C >> M;

    int dx[] = {0, 0, 0, 1, -1};
    int dy[] = {0, -1, 1, 0, 0};
    int d[] = {0, R, R, C, C};

    vector<shark> board[101][101];

    for (int i = 1; i <= M; i++) {
        int r, c, s, di, z;
        cin >> r >> c >> s >> di >> z;
        board[r][c].push_back({r, c, s, di, z});
    }

    int ret = 0;

    int angler_position = 0;

    while (true) {
        // 1
        angler_position++;
        if (angler_position > C) {
            break;
        }
        // 2
        for (int i = 1; i <= R; i++) {
            if (!board[i][angler_position].empty()) {
                ret += board[i][angler_position].back().size;
                board[i][angler_position].pop_back();
                break;
            }
        }
        // 3
        vector<shark> temp;
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                if (board[i][j].empty()) continue;
                shark s = board[i][j].back();
                int y = i;
                int x = j;

                int cnt = s.speed % (d[s.direction] * 2 - 2);

                while (cnt--) {
                    if (s.direction == 1 || s.direction == 2) {
                        if (y == 1) {
                            y = 2;
                            s.direction = 2;
                        } else if (y == R) {
                            y = R - 1;
                            s.direction = 1;
                        } else {
                            y += dy[s.direction];
                        }
                    } else if (s.direction == 3 || s.direction == 4) {
                        if (x == 1) {
                            x = 2;
                            s.direction = 3;
                        } else if (x == C) {
                            x = C - 1;
                            s.direction = 4;
                        } else {
                            x += dx[s.direction];
                        }
                    }
                }

                s.y = y;
                s.x = x;
                temp.push_back(s);

                board[i][j].pop_back();
            }
        }

        for (auto shark: temp) {
            if (board[shark.y][shark.x].empty()) {
                board[shark.y][shark.x].push_back(shark);
            } else {
                if (board[shark.y][shark.x].back().size < shark.size) {
                    board[shark.y][shark.x].pop_back();
                    board[shark.y][shark.x].push_back(shark);
                }
            }
        }
    }


    cout << ret;

    return 0;
}
