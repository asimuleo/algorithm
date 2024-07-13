//
// Created by cs.javah on 2024. 7. 10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>

using namespace std;

int H, W;

void play(vector<vector<int> > &board, int y, int x, int n) {

    board[y][x] = n;

    if (x + 1 < W && board[y][x + 1] != 0)
        play(board, y, x + 1, n + 1);

}


/**

*/
void p_10709() {

    cin >> H >> W;

    vector<vector<int> > board(H, vector<int>(W, -1));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == 'c')
                board[i][j] = 0;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == 0)
                //가즈아
                play(board, i, j, 0);
        }
    }


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }

}