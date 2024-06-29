//
// Created by csjav on 24. 6. 29.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>

using namespace std;

#define MAX 1000000000

// N명의 점원들
// 높이가 B 이상인 탑
int n, b;

// 각 점원의 키는 H
// h 의 모든 조합 중에
int com(vector<int> &h, vector<int> &sums, int sum, int step) {
    // 기저사례
    if (step == h.size()) {
        if (sum < b) return MAX;
        return sum;
    }

    // step 부터 끝까지의 합을 더해도 b 보다 작으면 할 필요가 없다.
    if (sum + sums[step] < b) return MAX;

    int ret = MAX;

    // 아 여기서 for 문 안넣어도 되는데 지능 떨어져서 시간 낭비 엄청했따... ㅠㅠ


    // 이미 결과가 최선의 값이라면 할 필요가 없다.
    if (ret == b) return ret;
    ret = min(com(h, sums, sum + h[step], step + 1), ret);
    ret = min(com(h, sums, sum, step + 1), ret);

    return ret;
}


/**
 * 서점에는 높이가 B인 선반
 * N명의 점원들
 * 각 점원의 키는 H (1 ≤ H ≤ 10,000)
 *
 * 높이가 B 이상인 탑 중에서 높이가 가장 낮은 탑을 알아내려고 한다.
 */
void 장훈이의높은선반() {
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> n >> b;
        // 그냥 정렬 한 뒤에 높은 사람 먼저 넣으면 되지 않음?
        // 이라고 하기에는 점원이 겁나게 많으면 아닐 수 도 있다.

        // 그럼 뒤에서부터 먼저 넣으면서 완전탐색
        // 대신 조건을 추가하자, 0~i 까지의 합을 sum[i] 에다가 저장한 후에
        // sum[i] 을 더했을 때 b 가 안되면


        // 사실 생각해 보니 조합으로 완전 탐색 하면 될듯 2의20제곱 = 1048576 가능

        // 했는데 시간 초과

        // 그래서 생각 했던 방법 적용.
        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        // 끝에서 부터 i 까지의 합 = sum[i]
        vector<int> sums(n);
        sums[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sums[i] = sums[i + 1] + h[i];
        }

        int ret = com(h, sums, 0, 0) - b;
        cout << '#' << test_case << ' ' << ret << endl;
    }
}
