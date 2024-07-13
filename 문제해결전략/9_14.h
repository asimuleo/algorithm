//
// Created by 임혁 on 2024. 5. 23..
//

/**
 * 코드 9.14 순열의 사전순 번호 찾기
 */

#include "iostream"
#include <vector>

using namespace std;

// factorials[i] = i!
int factorials[12];

// X의 각 원소가 [0..n-1]의 순열일 때 사전순 번호를 반환한다. (0에서 시작)
int getIndex(const vector<int>& X) {
    int ret = 0;
    for (int i = 0; i < X.size(); ++i) {
        int less = 0;
        for (int j = i + 1; j < X.size(); ++j)
            if (X[i] > X[j])
                less++;
        ret += factorials[X.size() - i - 1] * less;
    }
    return ret;
}

void test_9_14() {
    cout << getIndex(vector<int>{2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11});
}