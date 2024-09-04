//
// Created by SSAFY on 24. 9. 4.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point_tree {
    int y;
    int x;
    int age;
};

struct tree {
    int age;
    int past;

    explicit tree(int age): age(age), past(0) {
    }

    tree(int age, int past): age(age), past(past) {
    }
};


struct land {
    int food;
    deque<tree> trees;

    land() : food(5) {
    }
};

//  K년이 지난 후 살아남은 나무의 수를 출력한다.
int p_16235() {
    // 8방위
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 땅 크기
    int M; // 나무 개수
    int K; // K년 반복
    cin >> N >> M >> K;

    land board[11][11];

    int A[N + 1][N + 1]; // 기계가 주는 양분 값
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
        }
    }

    // 상도의 나무 심기!
    for (int i = 0; i < M; ++i) {
        int x; // 나무의 x
        int y; // 나무의 y
        int z; // 나무의 나이
        cin >> y >> x >> z;
        board[y][x].trees.push_back(tree{z});
    }

    while (K--) {
        // 봄
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                auto &land = board[i][j];
                int size = land.trees.size();
                vector<tree> temp;
                while (size-- > 0) {
                    auto t = land.trees.front();
                    land.trees.pop_front();
                    if (land.food - t.age < 0) {
                        temp.push_back(tree{-1, t.age});
                    } else {
                        land.trees.push_back(tree{t.age + 1});
                        land.food -= t.age;
                    }
                }

                for (auto t: temp) {
                    land.trees.push_front(t);
                }
            }
        }

        // 여름
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                auto &land = board[i][j];
                while (!land.trees.empty()
                       && land.trees.front().age == -1) {
                    land.food += land.trees.front().past / 2;
                    land.trees.pop_front();
                }
            }
        }

        // 가을
        vector<point_tree> point_trees;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                auto &trees = board[i][j].trees;
                for (auto t: trees) {
                    if (t.age % 5 != 0) continue;
                    for (int k = 0; k < 8; ++k) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
                        point_trees.push_back(point_tree{ny, nx, 1});
                    }
                }
            }
        }

        for (auto pt: point_trees) {
            board[pt.y][pt.x].trees.push_front(tree{pt.age});
        }

        // 겨울
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                board[i][j].food += A[i][j];
            }
        }
    }

    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            auto &land = board[i][j];
            ret += land.trees.size();
        }
    }
    cout << ret;

    return 0;
}
