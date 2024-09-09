//
// Created by SSAFY on 24. 9. 9.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

struct point
{
    int y;
    int x;
};

struct virus
{
    int y;
    int x;
};

// 연구소의 모든 빈 칸에 바이러스가 있게 되는 최소 시간을 출력한다.
int p_17142()
{
    constexpr int dy[] = {-1, 0, 1, 0};
    constexpr int dx[] = {0, 1, 0, -1};

    int N, M;
    cin >> N >> M;
    int board[N][N];
    vector<virus> viruses;
    int virus_cnt = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                viruses.push_back({i, j});
                virus_cnt++;
            }
        }
    }

    vector<int> p(virus_cnt - M, 0);
    p.insert(p.end(), M, 1);

    int ret = INT_MAX;

    do
    {
        int visited[N][N];
        memset(visited, -1, sizeof(visited));
        for (int i = 0; i < virus_cnt; ++i)
        {
            if (p[i] != 0)
            {
                // bfs
                queue<point> q;
                q.push({viruses[i].y, viruses[i].x});
                visited[viruses[i].y][viruses[i].x] = 0;
                while (!q.empty())
                {
                    const point u = q.front();
                    q.pop();
                    for (int j = 0; j < 4; ++j)
                    {
                        const int ny = dy[j] + u.y;
                        const int nx = dx[j] + u.x;
                        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                        if (board[ny][nx] == 1) continue;
                        if (visited[ny][nx] == -1 || visited[ny][nx] > visited[u.y][u.x] + 1)
                        {
                            q.push({ny, nx});
                            visited[ny][nx] = visited[u.y][u.x] + 1;
                        }
                    }
                }
            }
        }
        // 연구소가 모두 바이러스로 가득 찾는지 확인
        bool check = true;
        int time = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (board[i][j] == 1) continue;
                if (visited[i][j] == -1 && board[i][j] == 0)
                {
                    check = false;
                    goto next;
                }
                if (board[i][j] != 2)
                {
                    time = max(time, visited[i][j]);
                }
            }
        }
        // 최소 시간 저장
    next:
        if (check) ret = min(ret, time);
    }
    while (next_permutation(p.begin(), p.end()));

    // 최소 시간 출력
    cout << (ret == INT_MAX ? -1 : ret);

    return 0;
}
