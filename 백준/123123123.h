#include <iostream>
#include <cmath>

using namespace std;

int N, R, C;
int result = 0;

// https://www.acmicpc.net/problem/1074
void solve(long long n, int r, int c, int num) {
    if (n == 1) {
        cout << "R: " << R << ", ";
        cout << "C: " << C << ", ";
        cout << "r: " << r << ", ";
        cout << "c: " << c << ", ";
        if (R - 1 == r && C - 1 == c) {
            result = num;
        }
        cout << endl;
    } else {
        long long n1 = n / 4;
        int l1 = (num + 1) / 4;
        int l2 = (num + 1) / 2;
        int l3 = (num + 1) / 4 * 3;
        int l4 = num;
        int halfR = r / 2;
        int halfC = c / 2;

        solve(n1, r - halfR, c - halfC, l1 - 1);
        solve(n1, r - halfR, c, l2 - 1);
        solve(n1, r, c - halfC, l3 - 1);
        solve(n1, r, c, l4);
    }
}

void rec(long long N) {
    if (N == 4) {
        return;
    }
    cout << N / 4 << '\n';
    rec(N / 4);
}

void p_123123123() {
    cin >> N >> R >> C;
    R += 1;
    C += 1;
    long val = pow(2, N);
    solve(val * val, val - 1, val - 1, val * val - 1);
    cout << result;
}
