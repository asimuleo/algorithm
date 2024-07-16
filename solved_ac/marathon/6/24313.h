//
// Created by cs.javah on 2024. 7. 16.
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

using namespace std;


/**

*/
void p_24313() {
    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    // O(g(n)) = {f(n) | 모든 n ≥ n0에 대하여 f(n) ≤ c × g(n)인 양의 상수 c와 n0가 존재한다}
    // 함수 f(n) = a1n + a0, 양의 정수 c, n0가 주어질 경우 O(n) 정의를 만족하는지 알아보자.

    int a1, a0;
    cin >> a1 >> a0;

    int c;
    cin >> c;


    int n0;
    cin >> n0;

    for (int i = n0; i <= 100; ++i) {
        if (a1 * i + a0 <= c * i) continue;
        cout << 0;
        return;
    }

    cout << 1;
}
