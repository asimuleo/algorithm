//
// Created by SSAFY on 24. 9. 13.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct shark {
    int y;
    int x;
    int b; // 방향
};

struct fish {
    int y;
    int x;
    int a; // 물고기 번호
    int b; // 방향
    bool empty;
};

// 8방향
constexpr int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
constexpr int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};


int play(fish list[], fish *board[][4], shark sh) {
    // 물고기 이동!
    for (int i = 1; i <= 16; ++i) {
        auto &fi = list[i];
        if (fi.empty) continue;
        // 방향 탐색
        int d = fi.b;
        for (int j = 1; j <= 8; ++j) {
            // 벽이다
            // 상어다
            const int ny = dy[d] + fi.y;
            const int nx = dx[d] + fi.x;
            if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) {
                d++;
                if (d == 9) d = 1;
                continue;
            }
            if (ny == sh.y && nx == sh.x) {
                d++;
                if (d == 9) d = 1;
                continue;
            }

            // 교환!
            const auto temp = board[ny][nx];
            board[fi.y][fi.x] = temp;
            board[ny][nx] = &fi;

            // 좌표 수정!
            board[fi.y][fi.x]->y = fi.y;
            board[fi.y][fi.x]->x = fi.x;
            board[ny][nx]->y = ny;
            board[ny][nx]->x = nx;

            // 방향 수정
            board[ny][nx]->b = d;

            break;
        }
    }

    // 상어 이동!

    // 물고기 고르기
    int ret = 0;
    for (int ny = sh.y + dy[sh.b], nx = sh.x + dx[sh.b];
         ny < 4 && nx < 4 && ny >= 0 && nx >= 0;
         ny = ny + dy[sh.b], nx = nx + dx[sh.b]) {
        if (board[ny][nx]->empty) continue;

        fish t_list[17];
        copy(list, list + 17, t_list);

        fish *t_board[4][4];
        for (int i = 1; i <= 16; ++i) {
            t_board[t_list[i].y][t_list[i].x] = &t_list[i];
        }

        const auto fi = t_board[ny][nx];
        fi->empty = true;
        shark t_sh = {fi->y, fi->x, fi->b};
        // 냠냠
        int temp = fi->a;
        ret = max(ret, play(t_list, t_board, t_sh) + temp);

    }

    return ret;


}

// 상어가 먹을 수 있는 물고기 번호의 합의 최댓값을 출력한다.
int p_19236() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fish list[17];

    fish *board[4][4]; // 공간

    for (int i = 1; i <= 16; ++i) {
        list[i] = fish{-1, -1, i, -1, false};
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int a, b;
            cin >> a >> b;
            list[a].b = b;
            list[a].y = i;
            list[a].x = j;
            board[i][j] = &list[a];
        }
    }



    // 시작!
    int s_temp = board[0][0]->a;
    shark sh{0, 0, board[0][0]->b};
    board[0][0]->empty = true;

    cout << s_temp + play(list, board, sh);

    return 0;
}
