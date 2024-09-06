//
// Created by SSAFY on 24. 9. 6.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct sort_count {
    int index;
    int times;
};

int board[100][100];

int row_cnt = 3;
int col_cnt = 3;


void print_board() {
    for (int i = 0; i < row_cnt; i++) {
        for (int j = 0; j < col_cnt; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


int p_17140() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c, k;
    cin >> r >> c >> k; // 목표
    r--;
    c--;


    memset(board, 0, sizeof(board));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> board[i][j];
        }
    }

    int time = 0;


    // count row_count_array[100][101];
    // count col_count_array[100][101];
    // for (int i = 0; i < 100; ++i) {
    //     for (int j = 0; j < 101; ++j) {
    //         row_count_array[i][j] = {j, 0};
    //         col_count_array[i][j] = {j, 0};
    //     }
    // }

    while (board[r][c] != k && time <= 100) {
        if (row_cnt >= col_cnt) {
            // R 연산
            for (int i = 0; i < row_cnt; ++i) {
                // 정렬 수행
                vector<sort_count> count_vector;
                int count_array[101];
                memset(count_array, 0, sizeof(count_array));
                for (int j = 0; j < col_cnt; ++j) {
                    count_array[board[i][j]]++;
                }

                for (int j = 1; j <= 100; ++j) {
                    if (count_array[j] != 0) {
                        count_vector.push_back({j, count_array[j]});
                    }
                }
                sort(count_vector.begin(), count_vector.end(),
                     [](const sort_count &a, const sort_count &b) -> bool {
                         if (a.times == b.times) {
                             return a.index < b.index;
                         }
                         return a.times < b.times;
                     });
                int new_col_cnt = 0;
                for (const sort_count sc: count_vector) {
                    board[i][new_col_cnt++] = sc.index;
                    board[i][new_col_cnt++] = sc.times;
                    if (new_col_cnt == 100) {
                        break;
                    }
                }
                for (int j = new_col_cnt; j < col_cnt; ++j) {
                    board[i][j] = 0;
                }
                col_cnt = max(col_cnt, new_col_cnt);
            }
        } else {
            // C 연산
            for (int j = 0; j < col_cnt; ++j) {
                // 정렬 수행
                vector<sort_count> count_vector;
                int count_array[101];
                memset(count_array, 0, sizeof(count_array));
                for (int i = 0; i < row_cnt; ++i) {
                    count_array[board[i][j]]++;
                }

                for (int i = 1; i <= 100; ++i) {
                    if (count_array[i] != 0) {
                        count_vector.push_back({i, count_array[i]});
                    }
                }
                sort(count_vector.begin(), count_vector.end(),
                     [](const sort_count &a, const sort_count &b) -> bool {
                         if (a.times == b.times) {
                             return a.index < b.index;
                         }
                         return a.times < b.times;
                     });
                int new_row_cnt = 0;
                for (const sort_count sc: count_vector) {
                    board[new_row_cnt++][j] = sc.index;
                    board[new_row_cnt++][j] = sc.times;
                    if (new_row_cnt == 100) {
                        break;
                    }
                }
                for (int i = new_row_cnt; i < row_cnt; ++i) {
                    board[i][j] = 0;
                }
                row_cnt = max(row_cnt, new_row_cnt);
            }
        }

        time++;
    }

    if (time > 100) {
        cout << -1;
    } else {
        cout << time;
    }


    return 0;
}
