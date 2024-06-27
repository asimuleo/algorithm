//
// Created by csjav on 24. 6. 27.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solve(int a, int b, bool r) {
    vector<int> A(a), B(b);
    if (r) {
        for (int i = 0; i < a; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < b; ++i) {
            cin >> B[i];
        }
    } else {
        for (int i = 0; i < b; ++i) {
            cin >> B[i];
        }

        for (int i = 0; i < a; ++i) {
            cin >> A[i];
        }
    }


    int ret = -1000000000;
    for (int i = 0; i < b-a+1; ++i) {
        int sum = 0;
        for (int j = 0; j < a; ++j) {
            sum += A[j] * B[i+j];
        }
        ret = max(ret, sum);
    }

    return ret;
}


void 두개의숫자열() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int a, b;
        cin >> a >> b;
        int ret = a < b ? solve(a, b, true) : solve(b, a, false);
        cout << '#' << test_case << ' ' << ret << endl;

    }
}
