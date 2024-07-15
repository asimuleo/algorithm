//
// Created by 임혁 on 24. 7. 15.
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

void p_17298() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 오큰수 저장
    vector<int> nums(N);
    vector<int> nge(N, -1);


    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int max2_index = nums.size()-1;

    for (int i = N - 2; i >= 0; --i) {

        if (nums[max2_index] < nums[i]) {
            max2_index = i;
            continue;
        }

        // 뒤 최대값보다 크다면 포기
        if (nums[i] >= nums[max2_index]) continue;


        /**
         *  이거 찾는데 4시간 걸렸다...
         */
        // 만약 숫자가 전이랑 같다면 오큰수도 같다.
        // 만약 숫자가 전 오큰수와 전수의 사이라면
        if (nge[i+1] != -1 && nums[i] >= nums[i+1] && nge[i+1] > nums[i]) {
            nge[i] = nge[i+1];
            continue;
        }


        // j 부터 오큰수를 찾는다.
        for (int j = i + 1; j <= max2_index; ++j) {
            if (nums[i] < nums[j]) {
                nge[i] = nums[j];
                break;
            }
        }

    }

    for (int i = 0; i < N; ++i) {
        cout << nge[i] << ' ';
    }

}