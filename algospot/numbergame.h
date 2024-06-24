//
// Created by 임혁 on 2024. 6. 24.
// 풀이 안보고 맞췄다!!!
//

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

int cache[51][51][2];

// 범위[s..e)와 누구 차례(1, 0)인지 주어졌을때 현우와 서하의 점수 차 의 최대값을 반환한다.
int maxScoreDiff(vector<int> &board, int s, int e, bool turn) {

    // 기저사례
    // 1. 하나 남았다.
    if (s + 1 == e) {
        if (turn) { // 현우 차례면
            return board[s];
        } else { // 서하 차례면
            return -board[s];
        }
    }
    // 2. 끝
    if (s == e) {
        return 0;
    }

    // 메모이제이션
    int &ret = cache[s][e][turn ? 1 : 0];
    if (ret != -1000000000) return ret;


    // 현우 차례일때
    if (turn) {
        int maxRet = -1000000000;
        // 왼쪽을 가져온다.
        maxRet = max(maxRet, board[s] + maxScoreDiff(board, s + 1, e, false));
        // 오른쪽을 가져온다.
        maxRet = max(maxRet, board[e - 1] + maxScoreDiff(board, s, e - 1, false));
        // 왼쪽 2개를 지운다.
        maxRet = max(maxRet, maxScoreDiff(board, s + 2, e, false));
        // 오른쪽 2개를 지운다.
        maxRet = max(maxRet, maxScoreDiff(board, s, e - 2, false));
        return ret = maxRet;
    } else {
        int minRet = 1000000000;
        // 왼쪽을 가져온다.
        minRet = min(minRet, -board[s] + maxScoreDiff(board, s + 1, e, true));
        // 오른쪽을 가져온다.
        minRet = min(minRet, -board[e - 1] + maxScoreDiff(board, s, e - 1, true));
        // 왼쪽 2개를 지운다.
        minRet = min(minRet, maxScoreDiff(board, s + 2, e, true));
        // 오른쪽 2개를 지운다.
        minRet = min(minRet, maxScoreDiff(board, s, e - 2, true));
        return ret = minRet;
    }

}

void numbergame() {
    int c;
    cin >> c;

    for (int test_case = 0; test_case < c; ++test_case) {
        int n;
        cin >> n;
        vector<int> board(n);
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
        }
        for (auto &i: cache) {
            for (auto &j: i) {
                for (int &k: j) {
                    k = -1000000000;
                }
            }
        }
        // 현우(true) 부터 시작
        cout << maxScoreDiff(board, 0, n, 1) << endl;
    }

}
