//
// Created by 임혁 on 2024. 6. 24.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 수학에서 전단사 함수(全單射函數, 영어: bijection, bijective function)는 두 집합 사이를 중복 없이 모두 일대일로 대응시키는 함수이다.


// canWin(board) = 틱택토 게임판이 현재 board일 때 이번 차례인 사람이 이길 수 있는지 반환한다.
// 이 함수는 메모라이징이 가능하다. 평범하게 생각하면 map<board> 를 할 수도 있다.
// 여기서는 3*3 배열인 board 를 9자리의 3진수로 보는 것이다.
// 3진수로 보는 이유는 board 에 들어갈 수 있는 값이 'X', 'O', '.' 이기 때문이다.
// 변환해줄 함수를 먼저 작성해보자.
int bijection(const vector<string> &board) {
    int ret = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ret *= 3; // board 한칸 당 한 자리수를 차지하기 때문에 3을 곱해준다.
            if (board[i][j] == 'o') ret++;
            else if (board[i][j] == 'x') ret += 2;
        }
    }
    return ret;
}

// 다음에 필요한 것은 기저사례를 책임 질 빙고!
bool isFinished(const vector<string> &board, char turn) {
    // 8가지 를 확인하면 된다.
    // 가로
    if (board[0][0] == turn && board[0][1] == turn && board[0][2] == turn) return true;
    if (board[1][0] == turn && board[1][1] == turn && board[1][2] == turn) return true;
    if (board[2][0] == turn && board[2][1] == turn && board[2][2] == turn) return true;
    // 세로
    if (board[0][0] == turn && board[1][0] == turn && board[2][0] == turn) return true;
    if (board[0][1] == turn && board[1][1] == turn && board[2][1] == turn) return true;
    if (board[0][2] == turn && board[1][2] == turn && board[2][2] == turn) return true;
    // 대각선
    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) return true;
    if (board[2][0] == turn && board[1][1] == turn && board[0][2] == turn) return true;
    return false;
}

// 마지막으로 canWin 을 작성하자.
// 다음 canWin 이 하나라도 -1을 반환하면 가능성이 있다는 것이다.
// 놓을 수 있는 모든 칸에 대한 canWin 의 결과 값 중 최소값을 구하고 그 값이 -1 이면 이길 수 있다는 것이다!
// 0이면 비긴다는 것이고 1이면 진다는 뜻.

int cache[19683];

int canWin(vector<string> &board, char turn) {

    // 기저사례: 내 turn 과 다른 turn 으로 빙고가 되어버렸다면 졌으니까 -1
    if (isFinished(board, 'o' + 'x' - turn)) return -1;

    // 메모라이징;
    int &ret = cache[bijection(board)];
    if (ret != -2) return ret;


    int minValue = 2;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '.') {
                board[i][j] = turn;
                minValue = min(minValue, canWin(board, 'o' + 'x' - turn));
                board[i][j] = '.';
            }
        }
    }

    if (minValue == 2 || minValue == 0) return ret = 0;
    return ret = -minValue; // 다음 턴의 결과의 반대가 내 결과이다.

}

void tictactoe() {

    int n;
    cin >> n;

    for (int test_case = 0; test_case < n; ++test_case) {
        vector<string> board;
        for (int i = 0; i < 3; ++i) {
            string s;
            cin >> s;
            board.push_back(s);
        }

        // 누구 차례인지 구하기
        int a = 0, b = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'o') a++;
                else if (board[i][j] == 'x') b++;
            }
        }

        // 게임은 항상 x부터 시작합니다.
        char turn = a >= b ? 'x' : 'o';
        fill(cache, cache + (19683), -2);
        int ret = canWin(board, turn);
        if (ret == 0) {
            cout << "TIE" << endl;
        } else if (ret == 1) {
            cout << turn << endl;
        } else {
            cout << (char) ('o' + 'x' - turn) << endl;
        }

    }


}

