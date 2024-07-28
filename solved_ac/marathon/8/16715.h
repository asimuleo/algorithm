//
// Created by 임혁 on 24. 7. 28.
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

void p_16715() {

    int N;
    cin >> N;

    int max_sum = 0;
    int max_base = 2;

    // 2진법 부터 N 진법 까지 차례대로 도전한다.
    for (int i = 2; i <= N; ++i) {

        int sum = 0;

        // N 을 i진법으로 표현한다.
        // 각 자리수를 sum 에 더한다.

        // Quotient,  remainder

        int quotient = N;
        int remainder;

        while (quotient != 1 && quotient != 0) {
            remainder = quotient % i;
            quotient = quotient / i;
            sum += remainder; // 나머지 가 자리수 이다.
        }

        sum += quotient;

        // max_sum 보다 크면 sum 을 max_sum 으로 저장한다.
        // max_base 도 i 로 저장한다.
        if (max_sum < sum) {
            max_sum = sum;
            max_base = i;
        }

    }

    // 첫째 줄에 자릿수 합의 최댓값과, 이때의 진법 수를 공백을 사이에 두고 출력한다.
    cout << max_sum << ' ' << max_base;

}