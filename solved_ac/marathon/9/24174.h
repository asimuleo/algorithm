//
// Created by csjav on 24. 8. 4.
//

#include <cstdio>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

int N, K;
vector<int> nums;

int cnt;

vector<int> result;


// nums[k] 를 루트로 하는 트리를 최소 힙 성질을 만족하도록 수정한다.
// nums[k] 의 두 자식을 루트로 하는 서브 트리는 최소 힙 성질을 만족하고 있다.
// n 은 배열 nums 의 전체 크기이며 최대 인덱스를 나타낸다.
void heapify(int k, int n) {
    int smaller;
    int left = 2 * k;
    int right = 2 * k + 1;
    if (right <= n) {
        if (nums[left] < nums[right]) {
            smaller = left;
        } else {
            smaller = right;
        }
    } else if (left <= n) {
        smaller = left;
    } else
        return;

    if (nums[smaller] < nums[k]) {
        swap(nums[k], nums[smaller]); // 원소 교환
        cnt++;
        if (cnt == K) {
            result = nums;
        }
        heapify(smaller, n);
    }
}

void build_min_heap() {
    for (int i = N / 2; i >= 1; --i) {
        heapify(i, N);
    }
}

void heap_sort() {
    build_min_heap();
    for (int i = N; i >= 2; --i) {
        swap(nums[1], nums[i]); // 원소 교환
        cnt++;
        if (cnt == K) {
            result = nums;
        }
        heapify(1, i - 1);
    }
}


void p_24174() {
    cin >> N >> K;
    nums = vector<int>(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> nums[i];
    }
    heap_sort();
    if (result.empty()) {
        cout << -1;
    } else {
        for (int i = 1; i < result.size(); ++i) {
            cout << result[i] << ' ';
        }
    }
}
