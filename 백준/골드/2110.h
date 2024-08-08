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


int N, C;

vector<int> board;


//
bool play(int current, int last) {
    // 채워야 하는 수가 남은 수 보다 크다면 불가
    if (C - 2 > N - last) return false;

    for (int i = 2; i < C; ++i) {
        // last 보다 큰 인덱스 중에서 current 보다 큰 걸 찾는다.
        int j = last + 1;
        while (j < N) {
            if (board[j] - board[last] >= current) {
                break;
            }
            j++;
        }
        if (j == N) {
            // 못 찾았다면
            return false;
        }
        last = j;
    }
    return true;
}

void p_2110() {
    cin >> N >> C;

    board = vector<int>(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    sort(board.begin(), board.end());

    int dis = N - 1;

    while (true) {
        for (int i = 0; i < N - dis; ++i) {
            // 2 개를 구한다.
            int current = board[i + dis] - board[i];
            if (play(current, i + dis)) {
                cout << current;
                return;
            }
        }
        dis--;
    }
}
