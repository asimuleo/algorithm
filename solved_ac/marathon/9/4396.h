//
// Created by csjav on 24. 8. 4.
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

// 8방위
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};


void p_4396() {
    int n;
    cin >> n;

    vector<vector<char> > board(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    bool game_end = false;

    vector<vector<char> > open(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> open[i][j];
            if (open[i][j] == 'x' && board[i][j] == '*') {
                game_end = true;
            }
        }
    }

    // 모든 열린 칸에 대하여
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if (game_end && board[i][j] == '*') {
                cout << '*';
            } else {
                if (open[i][j] == 'x') {
                    // 8방위에 대하여
                    int cnt = 0;
                    for (int k = 0; k < 8; ++k) {
                        int ny = i + dx[k];
                        int nx = j + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[ny][nx] == '*')
                            cnt++;
                    }
                    cout << cnt;
                } else {
                    cout << open[i][j];
                }
            }
        }
        cout << endl;
    }
}
