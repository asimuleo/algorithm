//
// Created by csjav on 24. 9. 17.
//

#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;


int N;
int mine[21][21];

void print_mine() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cout << mine[i][j] << ' ';
        }
        cout << endl;
    }
}

int p_17779() {
    constexpr int dx[] = {0, -1, 1, 0};
    constexpr int dy[] = {-1, 0, 0, 1};

    struct point {
        int y;
        int x;
    };

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N;
    int board[N + 1][N + 1];
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> board[i][j];
        }
    }


    int ret = INT_MAX;

    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            for (int d1 = 1; 1 <= x - d1; ++d1) {
                for (int d2 = 1; y + d1 + d2 <= N && x + d2 <= N; ++d2) {
                    int population[5];
                    memset(population, 0, sizeof(population));

                    memset(mine, 0, sizeof(mine));
                    int &fi = population[4];
                    // 경계선 채우기
                    // 1.
                    for (int i = 0; i <= d1; ++i) {
                        const int ny = y + i;
                        const int nx = x - i;
                        if (mine[ny][nx]) continue;
                        fi += board[ny][nx];
                        mine[ny][nx] = 5;
                    }
                    // 2.
                    for (int i = 0; i <= d2; ++i) {
                        const int ny = y + i;
                        const int nx = x + i;
                        if (mine[ny][nx]) continue;
                        fi += board[ny][nx];
                        mine[ny][nx] = 5;
                    }
                    // 3.
                    for (int i = 0; i <= d2; ++i) {
                        const int ny = y + d1 + i;
                        const int nx = x - d1 + i;
                        if (mine[ny][nx]) continue;
                        fi += board[ny][nx];
                        mine[ny][nx] = 5;
                    }
                    // 4.
                    for (int i = 0; i <= d1; ++i) {
                        const int ny = y + d2 + i;
                        const int nx = x + d2 - i;
                        if (mine[ny][nx]) continue;
                        fi += board[ny][nx];
                        mine[ny][nx] = 5;
                    }

                    // 내용 채우기

                    // 1
                    for (int i = 1; i <= d1; ++i) {
                        const int ny = y + i;
                        int nx = x - i + 1;
                        while (!mine[ny][nx]) {
                            fi += board[ny][nx];
                            mine[ny][nx] = 5;
                            nx++;
                        }
                    }
                    // 3.
                    for (int i = 0; i < d2; ++i) {
                        const int ny = y + d1 + i;
                        int nx = x - d1 + i + 1;
                        while (!mine[ny][nx]) {
                            fi += board[ny][nx];
                            mine[ny][nx] = 5;
                            nx++;
                        }
                    }


                    // 각 구역 채우기
                    // 1
                    for (int i = 1; i < y + d1; ++i) {
                        for (int j = 1; j <= x; ++j) {
                            if (mine[i][j]) continue;
                            mine[i][j] = 1;
                            population[0] += board[i][j];
                        }
                    }
                    // 2
                    for (int i = 1; i <= y + d2; ++i) {
                        for (int j = x + 1; j <= N; ++j) {
                            if (mine[i][j]) continue;
                            mine[i][j] = 2;
                            population[1] += board[i][j];
                        }
                    }
                    // 3
                    for (int i = y + d1; i <= N; ++i) {
                        for (int j = 1; j < x - d1 + d2; ++j) {
                            if (mine[i][j]) continue;
                            mine[i][j] = 3;
                            population[2] += board[i][j];
                        }
                    }
                    // 4
                    for (int i = y + d2 + 1; i <= N; ++i) {
                        for (int j = x - d1 + d2; j <= N; ++j) {
                            if (mine[i][j]) continue;
                            mine[i][j] = 4;
                            population[3] += board[i][j];
                        }
                    }

                    // 결과값
                    sort(population, population + 5);
                    ret = min(ret, population[4] - population[0]);
                }
            }
        }
    }

    cout << ret;

    return 0;
}
