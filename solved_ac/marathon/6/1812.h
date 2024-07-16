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
#include <cstring>

using namespace std;


/**
*   각 학생이 가지고 있는 사탕의 수를 구하는 프로그램을 작성하시오.
*
*/
void p_1812() {
    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    int N;
    cin >> N;

    // 1번 학생과 2번 학생이 가지고 있는 사탕의 수의 합
    // ~
    // 마지막으로 N번 학생과 1번 학생의 가지고 있는 사탕의 수의 합
    vector<int> sum(N);

    vector<int> nums(N);

    int min_index = 0;

    for (int i = 0; i < N; ++i) {
        cin >> sum[i];
        if (sum[i] < sum[min_index])
            min_index = i;
    }

    // 사탕 개수를 가정한다.
    for (int candy = 0; candy <= sum[min_index]; ++candy) {


        // 가정
        nums[min_index] = candy;


        for (int i = min_index + 1; i < N; ++i) {
            nums[i] = sum[i - 1] - nums[i - 1];
        }

        if (min_index != 0) {
            nums[0] = sum[N - 1] - nums[N - 1];
        }

        for (int i = 1; i < min_index; ++i) {
            nums[i] = sum[i - 1] - nums[i - 1];
        }

        int last_index = (min_index - 1 >= 0 ? min_index : N) - 1;

        // 가정성공
        if (candy == sum[last_index] - nums[last_index]) {
            for (int i = 0; i < N; ++i) {
                cout << nums[i] << '\n';
            }
            return;
        }


    }
}
