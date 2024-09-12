//
// Created by SSAFY on 24. 9. 12.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct yx
{
    int y;
    int x;
};

struct yxr
{
    int y;
    int x;
    int r;
};

int p_22949()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;

    yx start{};

    const int miro = 4 * k;
    char board[miro][miro];
    for (int i = 0; i < miro; ++i)
    {
        for (int j = 0; j < miro; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S') start = {i, j};
        }
    }

    constexpr int dy[] = {-1, 0, 1, 0, 0};
    constexpr int dx[] = {0, 1, 0, -1, 0};

    // [회전][칸][영역]
    int visited[4][miro][miro];
    memset(visited, -1, sizeof(visited));

    queue<yxr> q;
    q.push({start.y, start.x, 0});
    visited[0][start.y][start.x] = 0;

    while (!q.empty())
    {
        const yxr u = q.front();
        q.pop();


        for (int i = 0; i < 5; ++i)
        {
            int sy = u.y / 4 * 4;
            int sx = u.x / 4 * 4;
            // 1
            const int ny = u.y + dy[i];
            const int nx = u.x + dx[i];
            int ur = u.r;

            if (ny < 0 || ny >= miro || nx < 0 || nx >= miro) continue;
            if (sy != ny / 4 * 4 || sx != nx / 4 * 4)
            {
                if (board[ny][nx] == 'E')
                {
                    cout << visited[u.r][u.y][u.x] + 1;
                    return 0;
                }
                ur = 0;
                sy = ny / 4 * 4;
                sx = nx / 4 * 4;
            }


            int by = ny;
            int bx = nx;
            for (int j = 0; j < (4 - ur) % 4; ++j)
            {
                const int ty = bx + (sy - sx);
                const int tx = sx + (3 - (by - sy));
                by = ty;
                bx = tx;
            }

            if (board[by][bx] == '#') continue;
            if (board[by][bx] == 'E')
            {
                cout << visited[u.r][u.y][u.x] + 1;
                return 0;
            }
            // 2
            const int nr = (ur + 1) % 4;
            const int ry = nx + (sy - sx);
            const int rx = sx + (3 - (ny - sy));
            if (visited[nr][ry][rx] != -1) continue;
            visited[nr][ry][rx] = visited[u.r][u.y][u.x] + 1;
            q.push({ry, rx, nr});
        }
    }

    cout << -1;

    return 0;
}
