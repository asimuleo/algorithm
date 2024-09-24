#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


struct point
{
    int y;
    int x;
};

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int dd[] = {2, 4, 8, 1};

int N, M;
int board[51][51];

int p_2234()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // 서쪽에 벽이 있을 때는 1을,
            // 북쪽에 벽이 있을 때는 2를,
            // 동쪽에 벽이 있을 때는 4를,
            // 남쪽에 벽이 있을 때는 8을 더한 값이 주어진다.
            cin >> board[i][j];
        }
    }


    // 1. 이 성에 있는 방의 개수
    int room_cnt = 0;
    vector<int> room_size;
    int visited[M][N];
    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (visited[i][j] != -1) continue;
            room_size.push_back(1); // 크기가 0인 룸
            visited[i][j] = room_cnt; // 방번호
            queue<point> q;
            q.push({i, j});
            while (!q.empty())
            {
                const point p = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    if ((board[p.y][p.x] & dd[k]) == dd[k]) continue;
                    const int ny = p.y + dy[k];
                    const int nx = p.x + dx[k];
                    if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
                    if (visited[ny][nx] != -1) continue;
                    visited[ny][nx] = room_cnt; // 방 번호
                    room_size.back()++; // 방 크기 증가
                    q.push({ny, nx});
                }
            }
            room_cnt++;
        }
    }
    cout << room_cnt << endl;
    // 2. 가장 넓은 방의 넓이
    cout << *max_element(room_size.begin(), room_size.end()) << endl;
    // 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
    int ret = 0;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                if ((board[i][j] & dd[k]) == dd[k])
                {
                    const int ny = i + dy[k];
                    const int nx = j + dx[k];
                    if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
                    if (visited[i][j] != visited[ny][nx])
                    {
                        ret = max(ret, room_size[visited[i][j]] + room_size[visited[ny][nx]]);
                    }
                }
            }
        }
    }
    cout << ret;

    return 0;
}
