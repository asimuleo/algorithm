//
// Created by 임혁 on 24. 11. 7.
//


#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;

int main() {

    // 앞면이 H
    // 뒷면이 T

    // N 행 N 열을 이루어 탁자 위에 놓여 있다.

    // 임의의 한 행 또는 한 열에 놓인 N개의 동전을 모두 뒤집는 작업을 수행할 수 있다.
    // T 의 개수를 최소로 하려고 한다.
    // 이때 T 의 개수를 구하는 프로그램을 작성하시오.

    int N;
    cin >> N;
    string board[N];
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    // N 은 20개 까지 가능하다.
    // 2^^20 에 대하여 정답을 구할 때 더 이득인 쪽으로 정답을 구하면 되지 않나?
    // 행 또는 열이 정해진 상태에서 그 반대의 값은 항상 최적의 선택 하나 밖에 없다.
    // 그 최적의 선택은 그리디 하게 구할 수 있을 것 같다.
    // 즉 2 ^^ 20, 각각의 행 또는 열을 뒤집을지 말지를 결정만 하면 끝날 것 같다.
    // 0 부터 1 << 20 - 1 까지 진행한다


    int ret = 401;

    // 모든 조합을 진행한다.
    for (int i = 0; i < (1 << N); ++i) {

        // 이번 조합에서 T 의 개수
        int temp_cnt_t = 0;

        // 이번 조합에서 쓸 보드
        string temp_board[N];
        for (int j = 0; j < N; ++j) {
            temp_board[j] = board[j];
        }

        // 이번 조합의 보드를 채운다
        for (int j = 0; j < N; ++j) {
            if ((1 << j) & i) {
                // 이 행은 뒤집는다.
                for (int k = 0; k < N; ++k) {
                    temp_board[j][k] = board[j][k] == 'H' ? 'T' : 'H';
                }
            } else {
                // 이 행은 그대로 진행한다.
                for (int k = 0; k < N; ++k) {
                    temp_board[j][k] = board[j][k];
                }
            }
        }

        // 열에서 T의 개수를 세서 max(N - T, T) 를 더한다.
        for (int j = 0; j < N; ++j) {

            int temp_col_cnt_t = 0;

            for (int k = 0; k < N; ++k) {
                if (temp_board[k][j] == 'T') {
                    temp_col_cnt_t++;
                }
            }

            temp_cnt_t += min(N - temp_col_cnt_t, temp_col_cnt_t);
        }

        ret = min(ret, temp_cnt_t);

    }

    cout << ret;


    return 0;

}
