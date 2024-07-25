//
// Created by 임혁 on 24. 7. 25.
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


int N, K;

bool odd[500001];
int start_odd[500001];
bool even[500001];
int start_even[500001];

int step_cache[1001]; // step 에 기반해 동생의 위치를 가중치를 계산

// v를반환
int way(int w, int u) {
    switch (w) {
        case 0:
            return u - 1;
        case 1:
            return u + 1;
        case 2:
            return u * 2;
    }
}

int bfs() {
    // 경과 시간
    int step = 0;

    queue<pair<int, int> > q;
    q.emplace(N, step);
    even[N] = true;

    while (!q.empty()) {
        int u = q.front().first;
        int next_step = q.front().second + 1;
        q.pop();

        for (int i = 0; i < 3; ++i) {
            int v = way(i, u);
            // 동생 위치가 500,000을 넘는 경우에는 -1
            if (v < 0 || v > 500000) continue;
            // 수빈이가 0보다 작은 좌표로, 50만보다 큰 좌표로 이동하는 것은 불가능
            if (step_cache[next_step] > 500000) return -1;
            if (next_step % 2 == 0) {
                if (even[v])
                    continue;
            } else {
                if (odd[v])
                    continue;
            }

            if (v == step_cache[next_step]) {
                // 도달 했다면
                return next_step;
            }

            if (next_step % 2 == 0) {
                even[v] = true;
                start_even[v] = next_step;
            } else {
                odd[v] = true;
                start_odd[v] = next_step;
            }
            q.emplace(v, next_step);
        }
    }
    return -1;
}


/**
 * 수빈이가 동생을 찾을 수 없거나, 찾는 위치가 500,000을 넘는 경우에는 -1을 출력
 */
void p_17071() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if (N == K) {
        cout << 0;
        return;
    }


    step_cache[0] = K;
    for (int i = 1; i < 1001; ++i) {
        step_cache[i] = i + step_cache[i - 1];
        //    cout << step_cache[i] << endl;
    }

    int ret = bfs();

    for (int k = 0; k < 1001; k = k + 2) {
        if (step_cache[k] > 500000) break;
        if (even[step_cache[k]] && start_even[step_cache[k]] <= k) {
            if (ret == -1 || k <= ret) {
                ret = k;
                break;
            }
        }
    }
    for (int k = 1; k < 1001; k = k + 2) {
        if (step_cache[k] > 500000) break;
        if (odd[step_cache[k]] && start_odd[step_cache[k]] <= k) {
            if (ret == -1 || k <= ret) {
                ret = k;
                break;
            }
        }
    }


    cout << ret << endl;

}
