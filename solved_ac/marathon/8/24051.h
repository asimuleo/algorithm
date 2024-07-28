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

void p_24051() {

    // 배열 A의 크기 N(5 ≤ N ≤ 10,000)
    // 저장 횟수 K(1 ≤ K ≤ N2)
    int N, K;
    cin >> N >> K;
    int A[N];

    // A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // 저장 횟수
    int save_cnt = 0;
    int k_num;

    for (int i = 1; i < N; ++i) {

        int loc = i - 1;
        int new_item = A[i];

        while (loc >= 0 && A[loc] > new_item) {
            A[loc + 1] = A[loc];
            save_cnt++;
            if (save_cnt == K) {
                k_num = A[loc];
            }
            loc--;
        }

        // 초기 위치랑 같다면 바꿀 이유가 없다
        if (loc != i - 1) {
            A[loc + 1] = new_item;
            save_cnt++;
            if (save_cnt == K) {
                k_num = A[loc];
            }
        }

    }

    if (save_cnt < K) {
        cout << -1;
    } else {
        cout << k_num;
    }

}