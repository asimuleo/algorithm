//
// Created by cs.javah on 2024. 7. 19.
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

int N;

int cache[2][100001];

// 스티커 점수의 최댓값을 반환한다.
int play(vector<vector<int> > &board, bool start_y, int start_x) {

    if (start_x >= N)
        return 0;

    int &ret = cache[start_y][start_x];

    if (ret != -1)
        return ret;
    /**
     * 총 2가지 방법이 있다.
     *
     * 1. 주어진 칸으로 부터 대각선으로 이동한다.
     * 2. 주어진 칸으로 부터 나이트 만큼 이동한다.
     **/

    // 1.
    ret = max(ret, play(board, !start_y, start_x + 1) + board[start_y][start_x]);
    // 2.
    ret = max(ret, play(board, !start_y, start_x + 2) + board[start_y][start_x]);


    // cout << ret;
    // print_visited(used);

    return ret;
}

void p_9465() {


    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int test_case = 0; test_case < T; ++test_case) {
        cin >> N;
        vector<vector<int> > board(2, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            cin >> board[0][i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> board[1][i];
        }
        memset(cache, -1, sizeof(cache));

        cout << max(play(board, false, 0), play(board, true, 0)) << endl;
    }
}
