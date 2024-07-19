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

using namespace std;

int M, N, x, y;

void play() {
    long long first_a = x - 1;

    long long first_current_b = first_a % (N) + 1;

    if (first_current_b == y) {
        cout << first_a + 1 << endl;
        return;
    }

    while (true) {
        first_a += M;

        long long current_a = x;
        long long current_b = first_a % (N) + 1;

        if (current_b == y) {
            cout << first_a + 1 << endl;
            return;
        }

        if (current_a == current_b && current_b == x) {
            break;
        }

        if (first_current_b == current_b) {
            break;
        }
    }

    cout << -1 << endl;
}

void play2() {
    long long first_b = y - 1;

    long long first_current_a = first_b % (M) + 1;

    if (first_current_a == x) {
        cout << first_b + 1 << endl;
        return;
    }

    while (true) {
        first_b += N;

        long long current_a = first_b % (M) + 1;
        long long current_b = y;

        if (current_a == x) {
            cout << first_b + 1 << endl;
            return;
        }

        if (current_a == current_b && current_a == y) {
            break;
        }

        if (first_current_a == current_a) {
            break;
        }
    }

    cout << -1 << endl;
}


/**
 * 이 문제에서 돌아볼 만 한 점은 나머지는 반복된다는 것이다.
 *
 * 언제까지 확인 할 건지에 대해서
 * 1. 최대 공약수 까지 하기
 * 2. 처음 시작했던 수로 돌아오기
 *
 * 라는 방법이 있겠는데, 나는 2번을 선택해서 오래걸렸던 것 같다.
 */
void p_6064() {
    int T;
    cin >> T;
    for (int test_case = 0; test_case < T; ++test_case) {
        cin >> M >> N >> x >> y;

        if (M < N) {
            play2();
        } else {
            play();
        }
    }
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int gcd2(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}