//
// Created by 임혁 on 24. 9. 14.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// 1번 상어만 격자에 남게 되기까지 걸리는 시간을 출력한다.
// 단, 1000초가 넘어도 다른 상어가 격자에 남아 있으면 -1을 출력한다.
int p_19237() {

    int dx[] = {0, 0, 0, -1, 1};
    int dy[] = {0, -1, 1, 0, 0};

    struct shark {
        int num;
        int y;
        int x;
        int d;
        // 1 2 3 4
        int priority[5][4];
    };

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 격자
    // M: 상어 수
    // k: 냄새 지속 시간
    int N, M, k;
    cin >> N >> M >> k;

    list<shark> shark_list(M, shark{});

    int smell[N][N]; // 냄새를 남긴 상어 번호
    memset(smell, 0, sizeof(smell));
    int smell_cnt[N][N]; // 냄새의 지속 시간
    memset(smell_cnt, 0, sizeof(smell_cnt));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;
            if (num != 0) {
                auto it = shark_list.begin();
                advance(it, num - 1);
                it->num = num;
                it->y = i;
                it->x = j;
            }

        }
    }

    // d
    // 1: 위
    // 2: 아래
    // 3: 왼쪽
    // 4: 오른쪽
    for (auto &sh: shark_list) {
        cin >> sh.d;
    }

    for (auto &sh: shark_list) {
        for (int j = 1; j <= 4; ++j) {
            for (int l = 0; l < 4; ++l) {
                cin >> sh.priority[j][l];
            }
        }
    }

    // 맨 처음에는 모든 상어가 자신의 위치에 자신의 냄새를 뿌린다.
    for (auto &sh: shark_list) {
        smell[sh.y][sh.x] = sh.num;
        smell_cnt[sh.y][sh.x] = k;
    }

    int time = 1000;
    while (time--) {

        vector<shark *> shark_board[20][20];


        // 모든 상어가 동시에 상하좌우로 인접한 칸 중 하나로 이동
        for (auto &sh: shark_list) {

            int sd;
            int sy;
            int sx;

            // 그런 칸이 없으면 자신의 냄새가 있는 칸의 방향으로 잡는다
            for (auto d: sh.priority[sh.d]) {
                int ny = sh.y + dy[d];
                int nx = sh.x + dx[d];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (smell[ny][nx] != sh.num) continue;
                sd = d;
                sy = ny;
                sx = nx;
                break;
            }

            // 먼저 인접한 칸 중 아무 냄새가 없는 칸의 방향으로 잡는다.
            // 특정한 우선순위를 따른다.
            for (auto d: sh.priority[sh.d]) {
                int ny = sh.y + dy[d];
                int nx = sh.x + dx[d];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (smell[ny][nx]) continue;
                sd = d;
                sy = ny;
                sx = nx;
                break;
            }
            sh.d = sd;
            sh.y = sy;
            sh.x = sx;
            shark_board[sy][sx].push_back(&sh);
        }


        // 상어 생존기
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (shark_board[i][j].size() > 1) {
                    sort(shark_board[i][j].begin(), shark_board[i][j].end(),
                         [](const shark *a, const shark *b) -> bool { return a->num < b->num; });
                }
            }
        }
        auto it = shark_list.begin();
        while (it != shark_list.end()) {
            shark &sh = *it;
            if (shark_board[sh.y][sh.x][0]->num != sh.num) {
                it = shark_list.erase(it);
            } else {
                it++;
            }
        }

        // 냄새 옅어지기
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (smell_cnt[i][j] == 1) {
                    smell_cnt[i][j] = 0;
                    smell[i][j] = 0;
                } else if (smell_cnt[i][j] > 0) {
                    smell_cnt[i][j]--;
                }
            }
        }

        // 냄새 뿌리기
        for (auto &sh: shark_list) {
            smell_cnt[sh.y][sh.x] = k;
            smell[sh.y][sh.x] = sh.num;
        }

        if (shark_list.size() == 1) {
            cout << 1000 - time;
            return 0;
        }


    }

    // 1초마다 모든 상어가 동시에 상하좌우로 인접한 칸 중 하나로 이동

    // 자신의 냄새를 그 칸에 뿌린다. 냄새는 상어가 k번 이동하고 나면 사라진다.

    // 각 상어가 이동 방향을 결정할 때는, 먼저 인접한 칸 중 아무 냄새가 없는 칸의 방향으로 잡는다.


    cout << -1;
    return 0;
}
