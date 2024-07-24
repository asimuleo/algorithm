//
// Created by SSAFY on 24. 7. 24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

// 4방위 상 좌 하 우
int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, -1, 0, 1};


struct fish {
    int y;
    int x;
    int d;
};

pair<int, int> fish_move[9] = {
        {0,  0}, // 없당
        {-1, 0},
        {-1, -1},
        {0,  -1},
        {1,  -1},
        {1,  0},
        {1,  1},
        {0,  1},
        {-1, 1},
};


int M, S;

vector<fish> fishes;
fish megi;
int smell[4][4];
int visited[4][4];

void printSmell() {
    for (auto &i: smell) {
        for (int j: i) {
            cout << j << '\t';
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
        fishes.push_back(fish{y - 1, x - 1, d});
    }

    // 법사
    int y, x;
    cin >> y >> x;
    megi = fish{y - 1, x - 1, 0};

    // 냄세
    memset(smell, -1, sizeof(smell));
}

vector<fish> copied;

/**
 * 복제 시전! 물고기 위치를 기억한다.
 */
void remember_fish() {
    copied = fishes;
}

/**
 *  모든 물고기 이동
 */
void move_fish() {
    // 모든 물고기에 대해서
    for (auto &f: fishes) {
        int d = f.d;
        // 모든 방향에 대하여
        for (int i = 0; i < 8; ++i) {
            // 이동이 가능한가?

            int ny, nx;
            ny = f.y + fish_move[d].second;
            nx = f.x + fish_move[d].first;

            if ((nx < 0 || nx >= 4 || ny < 0 || ny >= 4) // 격자의 범위를 벗어나는가?
                || (ny == megi.y && nx == megi.x) // 법사가 있는 칸인가?
                || (smell[ny][nx] != -1)) { // 냄새가 있는 칸인가?
                // 반시계 회전
                d = (d == 1 ? 8 : d - 1);
                continue;
            }

            // 이동을 적용한다.
            f.y = ny;
            f.x = nx;
            f.d = d;

            return;

        }
    }
}

void dfs(int y, int x, int ret, vector<int> &step, vector<pair<vector<int>, int> > &result) {
    if (step.size() == 3) {
        result.emplace_back(step, ret);
        return;
    }

    for (int i = 1; i <= 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
        step.push_back(i);

        int sum = 0;

        if (visited[ny][nx] == 0) {
            for (auto &f: fishes) {
                if (f.x == nx && f.y == ny) sum++;
            }
        }

        visited[ny][nx]++;
        dfs(ny, nx, ret + sum, step, result);
        step.pop_back();
        visited[ny][nx]--;
    }
}

/**
 * 법사 이동 함수
 * 상은 1, 좌는 2, 하는 3, 우는 4
 */
void move_magician() {

    vector<int> step;
    vector<pair<vector<int>, int> > result;
    memset(visited, 0, sizeof(visited));
    dfs(megi.y, megi.x, 0, step, result);

    auto it = max_element(result.begin(), result.end(), [](pair<vector<int>, int> a, pair<vector<int>, int> b) -> bool {
        if (a.second == b.second) {
            for (int i = 0; i < 3; ++i) {
                if (a.first[i] == b.first[i]) continue;
                return a.first[i] > b.first[i];
            }
        }
        return a.second < b.second;
    });

    vector<int> way = it->first;

    cout << way[0] << way[1] << way[2] << endl;

    int t3x = dx[way[2]];
    int t3y = dy[way[2]];
    int t2x = dx[way[1]];
    int t2y = dy[way[1]];
    int t1x = dx[way[0]];
    int t1y = dy[way[0]];

    vector<fish> new_fish;

    // 물고기 제거 & 냄새 남기기

    for (auto &f: fishes) {
        if ((f.x == megi.x && f.y == megi.y)
            || (f.x == megi.x + t1x && f.y == megi.y + t1y)
            || (f.x == megi.x + t1x + t2x && f.y == megi.y + t1y + t2y)
            || (f.x == megi.x + t1x + t2x + t3x && f.y == megi.y + t1y + t2y + t3y)) {
            smell[f.y][f.x] = 0; // 냄새 남기기
        } else {
            new_fish.push_back(f);
        }
    }

    fishes = new_fish;

    // 마법사 이동
    megi.x += (t1x + t2x + t3x);
    megi.y += (t1y + t2y + t3y);
}

/**
 * 일정 냄새를 제거할 함수
 */
void vanish_smell() {
    for (auto &i: smell) {
        for (int &j: i) {
            if (j == 2)
                j = -1;
        }
    }
}

/**
 * 기억된 물고기 복제 함수
 */
void copying_fish() {
    for (auto &i: copied) {
        fishes.push_back(i);
    }
    copied.clear();
}

/**
 * 냄새 경과 시간을 증가
 */
void turn_end() {
    for (auto &i: smell) {
        for (int &j: i) {
            if (j != -1)
                j = j + 1;
        }
    }
}


void p_23290() {
    init();

    while (S-- > 0) {
        cout << S << endl;
        remember_fish();
        move_fish();
        //cout << "물고기 이동" << endl;
//        printBoard();
        move_magician();
        //cout << " 법사 이동" << endl;
        //printBoard();
        vanish_smell();
        //cout << "냄새 제거" << endl;
        //printSmell();
        copying_fish();
        //cout << "물고기 복제" << endl;
        printBoard();
        turn_end();
        //cout << "냄새 시간 추가" << endl;
        printSmell();

//        cout << megi.y << ':' << megi.x << endl;
//        cout << fishes.size() << endl;
    }


    cout << fishes.size();
}
