//
// Created by cs.javah on 2024. 7. 18.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

int N;

int move_time = 0;

int baby_shark_size = 2;
int baby_shark_eaten_cnt = 0;
int baby_shark_y;
int baby_shark_x;


// 주의! 상 좌 우 하 .

// int dx[] = {0, -1, 1, 0};
// int dy[] = {1, 0, 0, -1};
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

void eat(vector<vector<int> > &board, pair<int, int> u, vector<vector<int> > &visited) {
    // 식사
    // cout << "식사";
    // cout << u.first << ':' << u.second << endl;
    baby_shark_eaten_cnt++;
    if (baby_shark_size == baby_shark_eaten_cnt) {
        baby_shark_eaten_cnt = 0;
        baby_shark_size++;
    }

    // 식사 후 는 0으로
    board[u.first][u.second] = 0;

    // 기존 상어 자리는 0으로
    board[baby_shark_y][baby_shark_x] = 0;

    // 상어 자리 이동
    baby_shark_y = u.first;
    baby_shark_x = u.second;

    // 움직인 시간만큼 더하기
    move_time += visited[u.first][u.second];
}

void test_printB(const vector<vector<int> > &board) {
    cout << endl;
    cout << endl;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}


// 가까운 물고기를 찾아서 먹자!
bool play(vector<vector<int> > &board) {
    vector<vector<int> > visited(N, vector<int>(N, -1));

    // 가까운 물고기 찾기
    queue<pair<int, int> > q;

    q.push({baby_shark_y, baby_shark_x});
    visited[baby_shark_y][baby_shark_x] = 0;

    /// 최단 거리
    int min_distance = -1;
    vector<pair<int, int> > min_distance_arr;

    while (q.size()) {
        pair<int, int> u = q.front();
        q.pop();

        if (min_distance != -1 && min_distance < visited[u.first][u.second]) {
            break;
        }

        // 방문한 정점에 물고기가 있을 경우 식사
        if (
            board[u.first][u.second] >= 1 &&
            board[u.first][u.second] < baby_shark_size) {
            if (min_distance == -1)
                min_distance = visited[u.first][u.second];

            min_distance_arr.push_back({u.first, u.second});
        }

        // 모든 인접한 v 를 q에 넣는다.
        for (int i = 0; i < 4; i++) {
            int ny = u.first + dy[i];
            int nx = u.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (visited[ny][nx] != -1) continue;
            if (board[ny][nx] > baby_shark_size) continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[u.first][u.second] + 1;
        }
    }

    if (min_distance_arr.empty())
        return false;

    auto it = min_element(min_distance_arr.begin(), min_distance_arr.end(),
                          [](pair<int, int> a, pair<int, int> b) -> bool {
                              if (a.first == b.first) {
                                  return a.second < b.second;
                              }
                              return a.first < b.first;
                          });


    // 식사
    eat(board, *it, visited);

    return true;
}


void p_16236() {
    cin >> N;

    vector<vector<int> > board(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                baby_shark_y = i;
                baby_shark_x = j;
            }
        }
    }

    while (play(board)) {
        test_printB(board);
        cout << move_time;
    }

    cout << move_time;
}
