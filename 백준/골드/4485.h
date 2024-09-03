//
// Created by SSAFY on 24. 9. 3.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <cstdint>

using namespace std;

struct point {
    int y;
    int x;
};

struct dis {
    point p;
    int value;
};


int p_4485() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {-1, 0, 1, 0};


    int N;
    cin >> N;
    int p = 1;
    while (N != 0) {
        int board[N][N];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> board[i][j];
            }
        }
        int ret = board[0][0];

        int distance[N][N];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                distance[i][j] = INT32_MAX;
            }
        }
        bool visited[N][N]; // 방문 여부
        memset(visited, false, sizeof(visited));

        auto comp = [](const dis &i, const dis &j) { return i.value > j.value; };
        priority_queue<dis, vector<dis>, decltype(comp)> pq(comp);

        distance[0][0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            dis u = pq.top();
            pq.pop();

            const auto &up = u.p;
            visited[up.y][up.x] = true;

            // 방문하지 않은 인접한 모든 정점에 대하여 최신화
            for (int i = 0; i < 4; ++i) {
                const int ny = up.y + dy[i];
                const int nx = up.x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (visited[ny][nx]) continue;
                // 기존 길이보다 u에서 가는게 더 빠르면 변경
                if (distance[ny][nx] > distance[up.y][up.x] + board[ny][nx]) {
                    distance[ny][nx] = distance[up.y][up.x] + board[ny][nx];
                }
                pq.push({{ny, nx}, distance[ny][nx]});
            }
        }
        ret += distance[N - 1][N - 1];

        cout << "Problem " << p << ": " << ret << '\n';
        cin >> N;
        p++;
    }
    return 0;
}
