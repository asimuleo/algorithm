//
// Created by csjav on 24. 6. 29.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

/**
* 가로 N 세로 N만큼의 공간
*
* 지나갈 수 없는 장애물  1
* 주기적으로 사라졌다 나타나는 소용돌이 2
* 2초동안 유지되다가 1초동안 잠잠
* (단 ,한번 통과한 소용돌이 위에서는 머물러 있을 수 있다 )
*
* 도착 할 수 없다면 -1
*/

#define MAX 1000000000

// 경기장 크기
int n;
// 시작점, 도착점
int a, b, c, d;

// 4방위
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// 캐시
int cache[15][15][675];


// 경로의 최소값을 반환한다.  도착 할 수 없다면 -1
int play(vector<vector<int> > &board, vector<vector<bool> > &visited, int x, int y, int timer) {
    // 기저사례
    // 목적지에 도착 했을때
    if (y == c && x == d) return 0;

    // 캐싱
    int &ret = cache[x][y][timer];
    if(ret != -1) return ret;

    ret = MAX;
    // 4방위 중에서 최소를 반환.
    for (int i = 0; i < 4; ++i) {
        int step = 1;
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 경기장을 벗어났을떄
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        // 다음 위치를 방문했었다면
        if (visited[ny][nx] == true) continue;
        // 다음 위치가 장애물일때
        if (board[ny][nx] == 1) continue;

        visited[ny][nx] = true;

        if (board[ny][nx] == 2 && timer % 3 != 2) {
            step += 2 - timer % 3;
        }
        ret = min(ret, play(board, visited, nx, ny, timer + step) + step);


        visited[ny][nx] = false;
    }


    return ret;
}


// 시간이 지날떄마다 소용돌이를 변화시키는 함수.
// 3으로 나눴을 때 나머지가 2 이면 사라졌다.

void 수영대회결승전() {
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> n;
        vector<vector<int> > board; // 바다
        vector<vector<bool> > visited; // 바다

        for (int i = 0; i < n; ++i) {
            visited.emplace_back();
            board.emplace_back();
            for (int j = 0; j < n; ++j) {
                int temp;
                cin >> temp;
                board[i].push_back(temp);
                visited[i].push_back(false);
            }
        }

        // 시작점, 도착점
        cin >> a >> b >> c >> d;

        memset(cache, -1, sizeof(cache));
        int ret = play(board, visited, b, a, 0);
        if (ret == MAX) ret = -1;
        cout << '#' << test_case << ' ' << ret << endl;
    }
}
