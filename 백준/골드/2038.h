//
// Created by 임혁 on 24. 8. 05.
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
#include <climits>

using namespace std;

int play(int n) {
    if (n == 1) {
        return 1;
    }
    return 1 + play(n - play(play(n - 1)));
}

void p_2038() {
    // 어떤 수가 주어졌을 때, 해당 수가 수열상에 몇번 등장하는지를 구하시요.
    // 이 수열은 어떤 수 k 가 증가함에 따라 k 가 등장하는 횟수가 감소하지 않는 수열을 의미한다.
    // 1이 등장하는 횟수는 1로 고정한다.
    // 어떤수 k 에 대하여 k-1이 등장하는 횟수는 k 보다 같거나 커야 하는 수중에 제일 작은 수이다.
    // 1,
    // 2, 2,
    // 3, 3,
    // 4, 4, 4,
    // 5, 5, 5,
    // 6, 6, 6, 6,
    // 7, 7, 7, 7,
    // 8, 8, 8, 8,
    // 9, 9, 9, 9, 9,
    // 10, 10, 10, 10, 10,
    // 11, 11, 11, 11, 11,
    // 12, 12, 12, 12, 12, 12
    // a(n) = 1;
    // a(n + 1) = 1 + a(n + 1 - a(a(n)));
    int n;
    cin >> n;
    cout << play(n);

}
