//
// Created by SSAFY on 24. 9. 4.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// 크기가 1×1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인
// 정사각형의 개수를 구하는 프로그램을 작성하시오.
int p_15685() {
    int N; // 드래곤 커브의 개수
    cin >> N;

    int board[101][101]; // 좌표 평면
    memset(board, 0, sizeof(board));

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};

    for (int n = 0; n < N; ++n) {
        int x; // 시작 x 좌표
        int y; // 시작 y 좌표
        int d; // 시작 방향
        int g; // 세대
        cin >> x >> y >> d >> g;

        deque<int> q; // 방향의 순열
        q.push_back(d);

        while (g-- > 0) {
            // 돌리고 붙이기
            deque<int> temp;
            for (auto it = q.rbegin(); it != q.rend(); ++it) {
                temp.push_back((*it + 1) % 4);
            }

            for (int i: temp) {
                q.push_back(i);
            }
        }

        board[y][x] = 1;

        for (int i: q) {
            y = y + dy[i];
            x = x + dx[i];
            board[y][x] = 1;
        }
    }

    bool visited[101][101];
    memset(visited, false, sizeof(visited));

    int ret = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (board[i][j]
                && board[i + 1][j]
                && board[i][j + 1]
                && board[i + 1][j + 1]
            ) {
                visited[i][j] = true;
                ret++;
            }
        }
    }

    cout << ret;

    return 0;
}
