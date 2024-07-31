//
// Created by cs.javah on 2024. 7. 31.
//

#include <cstdio>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

struct point {
    int y;
    int x;
};

point one[] = {{0, 1}, {0, 1}, {1, 0}, {1, 0}};
point two[] = {{1, 0}, {1, 1}, {1, 1}, {1, -1}};

int N, M; // 세로, 가로 크기

vector<vector<int> > strength;
vector<vector<bool> > visited;


// 주어진 위치에서 부터 만들 수 있는 부메랑 강도의 최대값을 반환합니다.
int make(point p) {
    // 기저사례 : 끝에 다으면 끝
    if (p.y == N - 1 && p.x == M - 1) {
        return 0;
    }


    // 다음 포인트는?
    point next_p;
    if (p.x == M - 1) {
        next_p = {p.y + 1, 0};
    } else {
        next_p = {p.y, p.x + 1};
    }

    // 만약 현재 위치가 이미 사용됬다면? 다음 위치로~
    if (visited[p.y][p.x]) {
        return make(next_p);
    }

    int ret = 0;

    for (int i = 0; i < 4; ++i) {
        point p1 = {p.y + one[i].y, p.x + one[i].x};
        point p2 = {p.y + two[i].y, p.x + two[i].x};

        if (p1.y < 0 || p1.y >= N || p2.y < 0 || p2.y >= N ||
            p1.x < 0 || p1.x >= M || p2.x < 0 || p2.x >= M)
            continue;
        if (visited[p1.y][p1.x] || visited[p2.y][p2.x]) continue;

        visited[p.y][p.x] = true;
        visited[p1.y][p1.x] = true;
        visited[p2.y][p2.x] = true;
        if (i == 0) {
            ret = max(ret, strength[p.y][p.x] * 2 +
                           strength[p1.y][p1.x] +
                           strength[p2.y][p2.x] + make(next_p));
        } else {
            ret = max(ret, strength[p.y][p.x] +
                           strength[p1.y][p1.x] * 2 +
                           strength[p2.y][p2.x] + make(next_p));
        }

        visited[p.y][p.x] = false;
        visited[p1.y][p1.x] = false;
        visited[p2.y][p2.x] = false;
    }

    ret = max(ret, make(next_p));

    return ret;
}

void p_18430() {
    // 이 나무 재료는 NxM크기의 직사각형 형태
    // 나무 재료의 부위마다 그 강도가 조금씩 다르다.
    // 이때 부메랑의 중심이 되는 칸은 강도의 영향을 2배로 받는다.
    // 나무 재료의 형태와 각 칸의 강도가 주어졌을 때,
    // 길동이가 만들 수 있는 부메랑들의 강도 합의 최댓값을 출력하는 프로그램을 작성하시오.
    // 단, 나무 재료의 크기가 작아서 부메랑을 하나도 만들 수 없는 경우는 0을 출력한다.


    cin >> N >> M; // 1 ≤ N, M ≤ 5

    strength = vector<vector<int> >(N, vector<int>(M));
    visited = vector<vector<bool> >(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> strength[i][j];
        }
    }

    cout << make({0, 0});
}
