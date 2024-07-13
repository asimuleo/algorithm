//
// Created by 임혁 on 2024. 5. 27..
//

/**
 * 코드 9.16 웨브바짐 문제의 답을 모두 찾는 완전 탐색 알고리즘
 * https://www.algospot.com/judge/problem/read/ZIMBABWE
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// digits: e의 자릿수들을 정렬한 것
string e, digits;
int n, m;

/**
 * e의 자릿수로 만들 수 있는 숫자들을 모두 출력한다.
 * @param price 지금까지 만든 가격
 * @param taken 각 자릿수의 사용 여부
 */
void generate(string price, bool taken[15]) { // 2. 메모이제이션을 위해 정보를 쪼개자.
    // 기저 사례
    if (price.size() == n) {
        if (price < e) { // 1. 크기 비교 최적화 할 수 있지 않을까?
            cout << price << endl;
        }
        return;
    }
    // 1. 이전이 없거나
    // 2. 이번 자릿수랑 다르거나
    // 3. 이전이 이미 사용 됬거나
    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            if (i == 0 || digits[i-1] != digits[i-1] || taken[i-1]) {
                taken[i] = true;
                generate(price + digits[i], taken);
                taken[i] = false;
            }
        }
    }
}
