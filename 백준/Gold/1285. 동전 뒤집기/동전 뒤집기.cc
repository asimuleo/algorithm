#include <iostream>

using namespace std;

// n 행 n 열
int n;

int board[20];

int ret = 1000000000;

// step == n 까지 재귀
// 조합
// 가능한 가로 뒤집기의 모든 경우의 수를 다 뒤집은 후에
// base 에서 세로에 대한 최적을 구한다.
void play(int step) {

    // base
    if (step == n) {
        int temp = 0;

        // 각 세로에 대하여 뒤집은 것과 안 뒤집은 것의 뒷면(T)의 개수 최소를 temp 에 더한다.
        for (int i = 1; i < (1 << n); i *= 2) {
            int t_cnt = 0;
            for (int j = 0; j < n; j++) {
                if (board[j] & i) t_cnt++;
            }
            temp += min(t_cnt, n - t_cnt);
        }

        ret = min(ret, temp);
        return;
    }

    // 안 뒤집기
    play(step + 1);

    // 뒤집기
    board[step] = ~board[step];
    play(step + 1);

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    string str;
    // 각 행을 한개의 숫자로 board 에 저장
    for (int i = 0; i < n; i++) {
        cin >> str;
        int value = 1;
        for (const char c : str) {
            if (c == 'T') board[i] |= value;
            value *= 2;
        }
    }

    play(0);
    cout << ret;

    return 0;
}
