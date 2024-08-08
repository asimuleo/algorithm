//
// Created by 임혁 on 24. 8. 07.
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

int N, M;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

char board[1001][1001];

void p_2206() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> board[i][j];
        }
    }
}
