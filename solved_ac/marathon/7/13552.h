//
// Created by 임혁 on 24. 7. 23.
//

#include <iostream>
#include <cmath>
#include <string>


using namespace std;


void p_13552() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; // 점의 개수
    cin >> N;

    long long point[N][3];
    for (int i = 0; i < N; ++i)
        cin >> point[i][0] >> point[i][1] >> point[i][2];

    int M; // 쿼리 개수
    cin >> M;

    for (int i = 0; i < M; ++i) {
        long long x, y, z, r;
        cin >> x >> y >> z >> r;

        int ret = 0;

        for (int j = 0; j < N; ++j) {
            // p 가 구 안에 있는가?
            if (
                (x - point[j][0]) * (x - point[j][0])
                + (y - point[j][1]) * (y - point[j][1])
                + (z - point[j][2]) * (z - point[j][2])
                <= r * r
            )
                ret++;
        }

        cout << ret << '\n';
    }
}
