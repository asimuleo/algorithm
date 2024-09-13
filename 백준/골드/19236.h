//
// Created by SSAFY on 24. 9. 13.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct shark
{
    int y;
    int x;
    int b; // 방향
};

struct fish
{
    int y;
    int x;
    int a; // 물고기 번호
    int b; // 방향
    bool empty;
};

// 상어가 먹을 수 있는 물고기 번호의 합의 최댓값을 출력한다.
int p_19236()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    auto comp = [](const fish* a, const fish* b) -> bool { return a->a < b->a; };

    // 8방향
    constexpr int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
    constexpr int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

    fish list[17];
    for (int i = 1; i <= 16; ++i)
    {
        list[i] = fish{-1, -1, i, -1, false};
    }

    fish* board[4][4]; // 공간

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int a, b;
            cin >> a >> b;
            list[a].b = b;
            list[a].y = i;
            list[a].x = j;
            board[i][j] = &list[a];
        }
    }

    int ret = 0;

    // 시작!
    ret += board[0][0]->a;
    shark sh{0, 0, board[0][0]->b};
    board[0][0]->empty = true;

    while (true)
    {
        // 물고기 이동!
        for (int i = 1; i <= 16; ++i)
        {
            auto& fi = list[i];
            // 방향 탐색
            int d = fi.b;
            for (int j = 1; j <= 8; ++j)
            {
                // 벽이다
                // 상어다
                const int ny = dy[d] + fi.y;
                const int nx = dx[d] + fi.x;
                if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)
                {
                    d++;
                    if (d == 9) d = 1;
                    continue;
                }
                if (ny == sh.y && nx == sh.x)
                {
                    d++;
                    if (d == 9) d = 1;
                    continue;
                }

                // 교환!
                const auto temp = board[ny][nx];
                board[fi.y][fi.x] = temp;
                board[ny][nx] = &fi;

                // 좌표 수정!
                temp->y = fi.y;
                temp->x = fi.x;
                fi.y = ny;
                fi.x = nx;

                // 방향 수정
                fi.b = d;

                break;
            }
        }

        // 상어 이동!
        priority_queue<fish*, vector<fish*>, decltype(comp)> pq(comp);

        // 물고기 고르기
        for (int ny = sh.y + dy[sh.b], nx = sh.x + dx[sh.b];
             ny < 4 && nx < 4 && ny >= 0 && nx >= 0;
             ny = ny + dy[sh.b], nx = nx + dx[sh.b])
        {
            if (board[ny][nx]->empty) continue;
            pq.push(board[ny][nx]);
        }

        if (pq.empty())
        {
            break;
        }
        // 냠냠
        const auto fi = pq.top();
        fi->empty = true;
        ret += fi->a;
        // 상어 변경
        sh.y = fi->y;
        sh.x = fi->x;
        sh.b = fi->b;
    }

    cout << ret;

    return 0;
}
