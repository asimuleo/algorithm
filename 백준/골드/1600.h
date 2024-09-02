//
// Created by 임혁 on 24. 9. 2.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;


int p_1600() {

    int K;
    cin >> K;

    int W, H;
    cin >> W >> H;

    if (W == 1 && H == 1) {
        cout << 0;
        return 0;
    }

    int board[H][W];

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> board[i][j];
        }
    }

    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    int dmx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dmy[] = {-2, -1, 1, 2, 2, 1, -1, -2};


    int visited[H][W][K + 1];
    memset(visited, -1, sizeof(visited));

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    for (int i = 0; i <= K; ++i) {
        visited[0][0][i] = 0;
    }

    while (!q.empty()) {
        tuple<int, int, int> u = q.front();
        q.pop();
        int y, x, k;
        tie(y, x, k) = u;


        if (k < K) {
            for (int i = 0; i < 8; ++i) {
                int ny = y + dmy[i];
                int nx = x + dmx[i];
                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if (ny == H - 1 && nx == W - 1) {
                    cout << visited[y][x][k] + 1;
                    return 0;
                }
                if (visited[ny][nx][k + 1] != -1) continue;
                if (board[ny][nx] == 1) continue;
                visited[ny][nx][k + 1] = visited[y][x][k] + 1;
                q.emplace(ny, nx, k + 1);
            }
        }

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (ny == H - 1 && nx == W - 1) {
                cout << visited[y][x][k] + 1;
                return 0;
            }
            if (visited[ny][nx][k] != -1) continue;
            if (board[ny][nx] == 1) continue;
            visited[ny][nx][k] = visited[y][x][k] + 1;
            q.emplace(ny, nx, k);
        }
    }

    cout << -1;

    return 0;
}