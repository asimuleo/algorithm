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

void p_6230() {

    int N, M;
    cin >> N >> M;

    vector<int> high(N);
    vector<int> low(M);

    for (int i = 0; i < N; ++i) {
        cin >> high[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> low[i];
    }

    // 낮은 품질은 사지 않는다.

    // 구매할 수 있는 최대 건초의 수를 구하려면
    // 높은 품질 중에서 가장 높은 품질의 건초와  낮은 품질 중에서 가장 높은 품질의 건초를 묶음으로 하면 되지 않을까?
    sort(high.begin(), high.end());
    sort(low.begin(), low.end());

    int ret = 0;

    // 높은 품질의 건초의 수 만큼 반복한다.
    for (int i = 0; i < N; ++i) {

        // 높은 품질 중에서 가장 높운 것과 낮은 품질 중에서 가장 높은 것을 찾는다.
        // 만약 선택된 높은 품질이 낮은 품질 보다 작거나 같다면 <=  1만 더한다.
        // 아니라면 2를 더하고, 지운다.

        int selected_low_index = -1;

        // high[high_index] 보다 작은 수가 있는지 확인한다.
        for (int j = low.size() - 1; j >= 0; --j) {
            if (high.back() > low[j]) {
                selected_low_index = j;
                break;
            }
        }

        high.pop_back();
        if (selected_low_index == -1) {
            ret++;
        } else {
            low.erase(low.begin() + selected_low_index);
            ret += 2;
        }


    }

    cout << ret;

}