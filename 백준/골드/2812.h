//
// Created by cs.javah on 2024. 7. 23.
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

void p_2812() {
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    if (N <= K) {
        cout << 0;
        return;
    }

    string st = s.substr(K);

    for (int i = K - 1; i >= 0; --i) {
        // 새로운 녀석이 크거나 같다면
        if (st[0] <= s[i]) {
            // a < b 인 첫 a 를 찾아서 없애자
            int a_index = st.size() - 1;
            for (int j = 0; j < st.size() - 1; ++j) {
                if (st[j] < st[j+1]) {
                    a_index = j;
                    break;
                }
            }
            st.erase(a_index, 1);
            st = s[i] + st;
        }
    }

    cout << st;
}
