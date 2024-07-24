//
// Created by SSAFY on 24. 7. 24.
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
#include <cstring>

using namespace std;

// 4방위 상 좌 하 우
int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, -1, 0, 1};


struct fish {
    int y;
    int x;
    int d;
    bool magician;
};

pair<int, int> fish_move[9] = {
    {0, 0}, // 없당
    {-1, 0},
    {-1, -1},
    {0, -1},
    {1, -1},
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 1},
};


int M, S;

vector<fish> fishes;
fish megi;
int smell[4][4];

void printSmell() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << smell[i][j] << '\t';
        }
        cout << endl;
    }
}

void printFish(vector<fish> &fish) {
    cout << '{';
    for (auto &i: fish) {
        cout << i.d;
    }
    cout << '}';
}

void printBoard() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            vector<fish> p;
            for (auto &f: fishes) {
                if (f.x == j && f.y == i) {
                    p.push_back(f);
                }
            }
            if (megi.x == j && megi.y == i) {
                p.push_back(megi);
            }
            printFish(p);
            cout << '\t';
        }
        cout << endl;
    }
    cout << endl;
}


/**
 * 입력을 받아서 초기값을 설정한다
 */
void init() {
    cin >> M >> S;

    fishes = vector<fish>();

    // 물고기 넣기
    for (int i = 0; i < M; ++i) {
        int y, x, d;
        cin >> y >> x >> d;
        fishes.push_back(fish{y - 1, x - 1, d, false});
    }

    // 법사
    int y, x;
    cin >> y >> x;
    megi = fish{y - 1, x - 1, 0, true};

    // 냄세
    memset(smell, -1, sizeof(smell));
}

vector<fish> copyed;

/**
 * 복제 시전! 물고기 위치를 기억한다.
 */
void go_1() {
    copyed = fishes;
}


// 물고기가 d 방향으로 이동 가능한가?
bool go_2_can_move(fish &f, int d) {
    int dy, dx, ny, nx;
    tie(dx, dy) = fish_move[d];
    ny = f.y + dy;
    nx = f.x + dx;

    // 격자의 범위를 벗어나는가?
    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) return false;
    // 법사가 있는 칸인가?
    if (ny == megi.y && nx == megi.x) return false;
    // 냄새가 있는 칸인가?
    if (smell[ny][nx] != -1) return false;

    return true;
}

// d 에 대한 이동
void go_2_move(fish &f) {
    int d = f.d;
    // 모든 방향에 대하여
    for (int i = 0; i < 8; ++i) {
        // 이동이 가능한가?
        if (go_2_can_move(f, d)) {
            // 이동을 적용한다.
            int dy, dx;
            tie(dx, dy) = fish_move[d];
            f.y = f.y + dy;
            f.x = f.x + dx;
            f.d = d;
            return;
        }

        // 반시계 회전
        d = d == 1 ? 8 : d - 1;
    }
}

/**
 *  모든 물고기 이동
 */
void go_2() {
    // 모든 물고기에 대해서
    for (auto &f: fishes) {
        go_2_move(f);
    }
}

void dfs(int y, int x, int ret, vector<int> &step, vector<pair<int, int> > &result) {
    if (step.size() == 3) {
        result.push_back({step[0] * 100 + step[1] * 10 + step[2], ret});
        return;
    }

    for (int i = 1; i <= 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
        step.push_back(i);

        int sum = 0;
        find(step.begin(), step.end(), i)
        for (auto &f: fishes) {
            if (f.x == nx && f.y == ny) sum++;
        }

        dfs(ny, nx, ret + sum, step, result);
        step.pop_back();
    }
}

/**
 * 법사가 이동할 경로를 찾는 DFS 함수
 * 상은 1, 좌는 2, 하는 3, 우는 4
 */
tuple<int, int, int> go_3() {
    // 기본은 상상상
    tuple<int, int, int> s = {1, 1, 1};

    vector<int> step;
    vector<pair<int, int> > result;
    dfs(megi.y, megi.x, 0, step, result);

    auto it = max_element(result.begin(), result.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });

    string best_path = to_string(it->first);

    return {best_path[0] - '0', best_path[1] - '0', best_path[2] - '0'};
}

/**
 * 법사 이동 함수
 */
void go_4(tuple<int, int, int> t) {
    int t1x = dx[std::get<0>(t)];
    int t1y = dy[std::get<0>(t)];
    int t2x = dx[std::get<1>(t)];
    int t2y = dy[std::get<1>(t)];
    int t3x = dx[std::get<2>(t)];
    int t3y = dy[std::get<2>(t)];

    vector<fish> nfish;

    // 물고기 제거 & 냄새 남기기

    for (auto &f: fishes) {
        if (f.x == megi.x && f.y == megi.y) {
            smell[f.y][f.x] = 0;
        } else if (f.x == megi.x + t1x && f.y == megi.y + t1y) {
            smell[f.y][f.x] = 0;
        } else if (f.x == megi.x + t1x + t2x && f.y == megi.y + t1y + t2y) {
            smell[f.y][f.x] = 0;
        } else if (f.x == megi.x + t1x + t2x + t3x && f.y == megi.y + t1y + t2y + t3y) {
            smell[f.y][f.x] = 0;
        } else {
            nfish.push_back(f);
        }
    }
    fishes = nfish;

    // 마법사 이동
    megi.x += t1x + t2x + t3x;
    megi.y += t1y + t2y + t3y;
}

/**
 * 일정 냄새를 제거할 함수
 */
void go_5() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (smell[i][j] == 2)
                smell[i][j] = -1;
        }
    }
}

/**
 * 기억된 물고기 복제 함수
 */
void go_6() {
    for (int i = 0; i < copyed.size(); ++i) {
        fishes.push_back(copyed[i]);
    }
    copyed.clear();
}

/**
 * 냄새 시간을 증가시킬 함수
 */
void go_7() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (smell[i][j] != -1)
                smell[i][j]++;
        }
    }
}


void p_23290() {
    init();

    while (S-- > 0) {
        go_1(); // 물고기 위치 기억
        go_2(); // 물고기 이동
        //cout << "물고기 이동" << endl;
        //printBoard();
        tuple<int, int, int> t = go_3();
        go_4(t); // 법사 이동
        //cout << " 법사 이동" << endl;
        //printBoard();
        go_5(); // 냄새 제거
        //cout << "냄새 제거" << endl;
        //printSmell();
        go_6(); // 물고기 복제
        //cout << "물고기 복제" << endl;
        //printBoard();
        go_7(); // 냄새 시간 추가
        //cout << "냄새 시간 추가" << endl;
        //printSmell();
    }


    cout << fishes.size();
}
