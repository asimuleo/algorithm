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

// 부등호 개수
int k;

// 부등호
vector<char> sign;

// 숫자 선택 여부
bool visited[10];

vector<int> nums;

// 주어진 부둥호 인덱스에 대한 만족하는 값중 최대 값을 반환한다.
long long dfs_max(int sign_index) {
    if (sign_index == k) {
        // 완성된 nums 를 반환한다.
        long long num = 0;
        for (int n: nums) {
            num *= 10;
            num += n;
        }
        return num;
    }

    long long ret = 0;

    for (int i = 0; i < 10; ++i) {
        if (visited[i]) continue;
        int last = nums.back();
        if (sign[sign_index] == '<') {
            if (last >= i) continue;
        } else {
            if (last <= i) continue;
        }
        visited[i] = true;
        nums.push_back(i);
        ret = max(ret, dfs_max(sign_index + 1));
        nums.pop_back();
        visited[i] = false;
    }

    return ret;
}

// 주어진 부둥호 인덱스에 대한 만족하는 값중 최소 값을 반환한다.
long long dfs_min(int sign_index) {
    if (sign_index == k) {
        // 완성된 nums 를 반환한다.
        long long num = 0;
        for (int n: nums) {
            num *= 10;
            num += n;
        }
        return num;
    }

    long long ret = 9999999999;

    for (int i = 0; i < 10; ++i) {
        if (visited[i]) continue;
        int last = nums.back();
        if (sign[sign_index] == '<') {
            if (last >= i) continue;
        } else {
            if (last <= i) continue;
        }
        visited[i] = true;
        nums.push_back(i);
        ret = min(ret, dfs_min(sign_index + 1));
        nums.pop_back();
        visited[i] = false;
    }

    return ret;
}

void p_2529() {
    // 0부터 9중에서 하나씩 선택해서 만든 수 중에서 최대랑 최소를 구하면 되는 문제이다.
    // 단 부등호 조건을 만족해야 해당 자리에 들어 갈 수 있다.
    // 재귀 완탐으로 해결하면 될 것 같다.


    cin >> k;
    sign = vector<char>(k);

    for (int i = 0; i < k; ++i) {
        cin >> sign[i];
    }

    long long max_ret = -1;

    for (int i = 0; i < 10; ++i) {
        nums.push_back(i);
        visited[i] = true;
        max_ret = max(max_ret, dfs_max(0));
        visited[i] = false;
        nums.pop_back();
    }

    cout.width(k+1);
    cout.fill('0');
    cout << max_ret << '\n';

    long long min_ret = 9999999999;

    for (int i = 0; i < 10; ++i) {
        nums.push_back(i);
        visited[i] = true;
        min_ret = min(min_ret, dfs_min(0));
        visited[i] = false;
        nums.pop_back();
    }

    cout.width(k+1);
    cout.fill('0');
    cout << min_ret << endl;
}
