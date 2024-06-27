//
// Created by csjav on 24. 6. 27.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void 숫자배열회전() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int n;
        cin >> n;


        int rotated_procession[4][n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> rotated_procession[0][i][j];
            }
        }

        int ret[n][n * 3];


        for (int angle_step = 1; angle_step < 4; angle_step++) {
            // 90도 오른쪽으로 돌아간 행렬 구하기

            for (int x = 0; x < n; x++) {
                for (int y = n - 1; y >= 0; y--) {
                    rotated_procession[angle_step][x][n - y - 1] = rotated_procession[angle_step - 1][y][x];
                }
            }

            // 돌아간 행렬을 결과 배열에 집어넣기
            // [start, end)
            int start = 0 + (n * (angle_step - 1));
            int end = start + n;
            for (int i = 0; i < n; i++) {
                for (int j = start; j < end; j++) {
                    ret[i][j] = rotated_procession[angle_step][i][j - start];
                }
            }
        }

        // 결과 출력
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n * 3; j++) {
                cout << ret[i][j];
                if ((j + 1) % n == 0)
                    cout << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
