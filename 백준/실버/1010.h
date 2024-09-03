//
// Created by SSAFY on 24. 9. 3.
//

#include <iostream>
#include <cstring>
using namespace std;

int cache[31][31];

int play(int n, int m) {
    if (n == 0) {
        return 1;
    }

    int &ret = cache[n][m];
    if (ret != -1)
        return ret;

    ret = 0;

    for (int i = n - 1; i <= m - 1; i++) {
        ret += play(n - 1, i);
    }

    return ret;
}


int p_1010() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M; // N ≤ M
        memset(cache, -1, sizeof(cache));
        cout << play(N, M) << endl;
    }


    return 0;
}
