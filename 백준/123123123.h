#include <iostream>
#include <cmath>

using namespace std;

int N, R, C;
int result = 0;

// https://www.acmicpc.net/problem/1074
void solve(int n, int r, int c, int num) {
    if (n == 1) {
//        cout << "R: " << R << ", ";
//        cout << "C: " << C << ", ";
//        cout << "r: " << r << ", ";
//        cout << "c: " << c << ", ";
        if (R == r && C == c) {
            result = num;
        }
//        cout << endl;
    } else {

        /**
         * 각 4분면의 num 의 값을 나열 했을 때
         * n 이 4 일때는 더 작은 다음 4분면의 num 들은 1씩 증가고 0 1 2 3
         * n 이 16 일때는 4씩 증가고 -> 3 7 11 15
         * n 이 64 일때는 16씩 증가고 -> 15 31 47 63
         *
         * 즉 4사분면은 num 그대로
         * 3사분면의 num은 n/4 만큼 감소 // ex> n=64, 64/4=16, 63 - 16 -> 47
         * 2사분면의 num은 l3에서 n/4 빼기
         * 1사분면의 num은 l2에서 n/4 빼기
         */

        int l4 = num;
        int l3 = l4 - n / 4;
        int l2 = l3 - n / 4;
        int l1 = l2 - n / 4;

        // n = 64 인 경우를 예로 들어볼 때,
        // r 과 c 는 애초에 행과 열이기 떄문에 1차원이다.
        // 절반씩 줄어드는 것이 맞지만(r - halfR)
        // n의 제곱근을 해서 1차원으로 줄인 것을 뺴야한다.
        // 절반이니까 나누기 2도 해준 sqrt(n) / 2 를 빼주면 정답이다.
        solve(n / 4, r - sqrt(n) / 2, c - sqrt(n) / 2, l1);
        solve(n / 4, r - sqrt(n) / 2, c, l2);
        solve(n / 4, r, c - sqrt(n) / 2, l3);
        solve(n / 4, r, c, l4);
    }
}

void p_123123123() {
    cin >> N >> R >> C;
    int val = pow(2, N);
    // r, c 는 뺴기만 하기 떄문에 -1 을 여기서 빼도 되고 if (R == r && C == c) 에서 감소된 값을 비교해도 된다.
    // num은 0번쨰 방문부터 시작이기 떄문에,
    // 총 val * val칸중 -1을 뺸 val * val-1 번째 방문.
    solve(val * val, val - 1, val - 1, val * val - 1);
    cout << result;
}
