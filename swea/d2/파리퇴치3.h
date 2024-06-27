//
// Created by csjav on 24. 6. 27.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void 파리퇴치3() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int n, m;
        cin >> n >> m;
        int board[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }

        int ret = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // +
                int sum = 0;
                // 중앙
                sum += board[i][j];
                for (int k = 1; k < m; ++k) { // 세기
                    // 가로
                    // 왼쪽
                    if (j - k >= 0) {
                        sum += board[i][j - k];
                    }
                    // 오른쪽
                    if (j + k < n) {
                        sum += board[i][j + k];
                    }
                    // 세로
                    // 위쪽
                    if (i - k >= 0) {
                        sum += board[i - k][j];
                    }
                    // 아래쪽
                    if (i + k < n) {
                        sum += board[i + k][j];
                    }
                }
                ret = max(ret, sum);

                // *
                sum = 0;
                // 중앙
                sum += board[i][j];
                for (int k = 1; k < m; ++k) { // 세기
                    // 위쪽 - 오른쪽
                    if (i - k >= 0 && j + k < n) {
                        sum += board[i - k][j + k];
                    }
                    // 위쪽 - 왼쪽
                    if (i - k >= 0 && j - k >= 0) {
                        sum += board[i - k][j - k];
                    }
                    // 아래쪽 - 오른쪽
                    if (i + k < n && j + k < n) {
                        sum += board[i + k][j + k];
                    }
                    // 아래쪽 - 왼쪽
                    if (i + k < n && j - k >= 0) {
                        sum += board[i + k][j - k];
                    }
                }
                ret = max(ret, sum);
            }
        }

        cout << '#' << test_case << ' ' << ret << endl;

    }
}
