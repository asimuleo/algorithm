//
// Created by 임혁 on 2024. 6. 20.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <iomanip>
#include <list>


using namespace std;


void p_2875() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    // 여학생의 수 N, 남학생의 수 M, 인턴쉽에 참여해야하는 인원 K
    int n, m, k;
    cin >> n >> m >> k;

    /**
     * k를 제외해야 하는데 그 중에 남학생 수를 a 여학생 수를 b 라고 하고 가능한 모든 a, b 를 완전탐색 하자.
     */

    int max_team = -1;
    // x : 현재 남아있는 남학생 수
    // y : 현재 남아있는 여학생 수
    for (int a = 0; a <= k; ++a) {
        int b = k - a;

        int x = m - a;
        int y = n - b;

        if (x >= y) { // 남학생 수 가 더 많거나 같으면
            // 여학생 수에 2를 나눈 수가 팀 수다.
            max_team = max(max_team, y / 2);
        } else { // 여학생 수가 더 많으면
            // 남학생 수와 여학생 수를 2로 나눈 수 중에서 더 작은 수가 정답이다.
            max_team = max(max_team, min(y / 2, x));
        }

    }

    cout << max_team << endl;


}
