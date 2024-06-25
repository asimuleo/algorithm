//
// Created by 임혁 on 2024. 6. 25.
// 맞추긴 했다.  int cache 대신에 char 캐시를 쓰니까 괜찮아졌다.
// 1.6 초 걸렸는데 사실상 이게 맞는지는 잘 모르겠다.
// return 문 추가 했더니 1.3 초
// 레전드... 책 정답은 획기적이였다. 이걸 아냐 모르냐는 불을 발견하지 못한 인류와 지금의 차이와 같다.
//
// 첫번째는 충분히 시간을 들이면 생각할 수 있을 만 한 것이다.
// 단순히 board 를 문자로 채우지 말고 bool 로 표현하자는 것이였다.
// 여기서 두번째를 생각할 수 있게 된다.
//
// bool 배열 대신에 32비트 정수를 사용하는 것이다.
// (y, x) 칸의 블록이 이미 채워져있는지의 여부를 단순히 y * 5 + x 번 비트가 켜져 있는가로 판단하는 것이다.
// (5,5) 까지 있으니까 30번 비트까지가 의미있다.
// 내가 엄청 주구장창 길게 써놓은 조건문을 획기적으로 줄일 수 있다. 단순히 AND 연산만 하면 되는 것이다.
// 근데 더 엄청난게 남아있다. 이 발상은 진짜 말이 안된다.
//
// 애초에 놓을 수 있는 블록의 위치와 블록의 종류는 정해져 있고 이를 단순한 정수로 표현 가능하다는 것이다.
// (0,0)과 (1,1) 위치에 2칸짜리 블록이 놓여있다고 했을때,
// 이를 0번비트와 1번비트가 켜져있다고 생각하고, 숫자로 3이라고 생각한다는 것이다.
// 해당 블록을 게임판에 놓을 수 있는 여부를 판단하는 로직은
// 단순히 board 대신에 사용한 bool 배열 대신에 사용한 32 비트 정수와  블록 대신에 사용한 3을 AND 하면 되는 것이다.
// 결과가 0이면 놓을 수있다는 것이다.
// OR 연산을 통해 해당 블록을 board 에 채울 수 있다.



#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int bijection(vector<string> &board) {
    int ret = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            ret *= 2;
            if (board[i][j] == '#') ret += 1;
        }
    }
    return ret;
}

// 블록을 더 이상 올려놓을 수 없을 때 게임이 끝난다. (true 블록을 더이상 놓을 수 없다)
bool isFinished(vector<string> &board) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int a, b;
            if (board[i][j] == '.') {
                // 3가지 ㅏ
                a = i - 1, b = j;
                if (a >= 0 && board[a][b] == '.') {
                    return false;
                }
                a = i, b = j + 1;
                if (b < 5 && board[a][b] == '.') {
                    return false;
                }
                a = i + 1, b = j;
                if (a < 5 && board[a][b] == '.') {
                    return false;
                }
            }
        }
    }
    return true;
}

// 1:true 0:false -1:init
char cache[33554432];

// 이번 차례인 사람이 승리 할 수 있는가? (true 승리)
bool play(vector<string> &board) {

    // 기저사례
    if (isFinished(board)) return false;

    // 메모라이징
    char &ret = cache[bijection(board)];
    if (ret != -1) return ret;

    bool canWin = false;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int a, b, c, d;
            if (board[i][j] == '.') {
                // a, b
                // 2칸 가능성 -, l,
                a = i, b = j + 1;
                if (b < 5 && board[a][b] == '.') {
                    board[i][j] = '#';
                    board[a][b] = '#';
                    if (!play(board)) {
                        canWin = true;
                    }
                    board[i][j] = '.';
                    board[a][b] = '.';
                }
                if(canWin) {
                    return ret = 1;
                }
                a = i + 1, b = j;
                if (a < 5 && board[a][b] == '.') {
                    board[i][j] = '#';
                    board[a][b] = '#';
                    if (!play(board)) {
                        canWin = true;
                    }
                    board[i][j] = '.';
                    board[a][b] = '.';
                }
                if(canWin) {
                    return ret = 1;
                }
                // a, b, c, d
                // 3칸 가능성 ㄱ ㄴ ㅢ ㅏ
                a = i, b = j + 1, c = i + 1, d = j + 1;
                if (c < 5 && d < 5 && board[a][b] == '.' && board[c][d] == '.') {
                    board[i][j] = '#';
                    board[a][b] = '#';
                    board[c][d] = '#';
                    if (!play(board)) {
                        canWin = true;
                    }
                    board[i][j] = '.';
                    board[a][b] = '.';
                    board[c][d] = '.';
                    if(canWin) {
                        return ret = 1;
                    }
                }
                a = i + 1, b = j, c = i + 1, d = j + 1;
                if (c < 5 && d < 5 && board[a][b] == '.' && board[c][d] == '.') {
                    board[i][j] = '#';
                    board[a][b] = '#';
                    board[c][d] = '#';
                    if (!play(board)) {
                        canWin = true;
                    }
                    board[i][j] = '.';
                    board[a][b] = '.';
                    board[c][d] = '.';
                    if(canWin) {
                        return ret = 1;
                    }
                }
                a = i + 1, b = j, c = i + 1, d = j - 1;
                if (c < 5 && d >= 0 && board[a][b] == '.' && board[c][d] == '.') {
                    board[i][j] = '#';
                    board[a][b] = '#';
                    board[c][d] = '#';
                    if (!play(board)) {
                        canWin = true;
                    }
                    board[i][j] = '.';
                    board[a][b] = '.';
                    board[c][d] = '.';
                    if(canWin) {
                        return ret = 1;
                    }
                }
                a = i + 1, b = j, c = i, d = j + 1;
                if (a < 5 && d < 5 && board[a][b] == '.' && board[c][d] == '.') {
                    board[i][j] = '#';
                    board[a][b] = '#';
                    board[c][d] = '#';
                    if (!play(board)) {
                        canWin = true;
                    }
                    board[i][j] = '.';
                    board[a][b] = '.';
                    board[c][d] = '.';
                    if(canWin) {
                        return ret = 1;
                    }
                }

            }
        }
    }

    return ret = 0;

}

void blockgame() {
    int c;
    cin >> c;
    memset(cache, -1, sizeof(cache));
    for (int test_case = 0; test_case < c; ++test_case) {
        vector<string> board(5);
        for (int i = 0; i < 5; ++i) {
            cin >> board[i];
        }
        // 25자리 2진수 = 33554432 가능.
        cout << (play(board) ? "WINNING" : "LOSING") << endl;
    }
}