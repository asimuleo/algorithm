//
// Created by csjav on 24. 6. 30.
//


#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
// * S는 가위, P는 보, R은 바위
// 이기면 2 비기면 1 지면 0
int play(char a, char b) {

    if (a == 'S') {
        if (b == 'S') {
            return 1;
        }
        if (b == 'P') {
            return 2;
        }
        return 0;
    }

    if (a == 'P') {
        if (b == 'S') {
            return 0;
        }
        if (b == 'P') {
            return 1;
        }
        return 2;
    }

    if (b == 'S') {
        return 2;
    }
    if (b == 'P') {
        return 0;
    }
    return 1;

}


/**
* 친구 N명과 동시에
* 총 R개의 라운드
* 이기면 2점, 비기면 1점, 지면 0점
* S는 가위, P는 보, R은 바위
*
* 첫째 줄에 상근이의 점수
* 둘째 줄에는 상근이가 얻을 수 있는 최대 점수
*
*/
void p_2930() {
    int r;
    cin >> r;

    vector<char> a(r);
    for (int i = 0; i < r; ++i) {
        cin >> a[i];
    }

    int n;
    cin >> n;
    vector<vector<char> > b(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < r; ++j) {
            char c;
            cin >> c;
            b[i].push_back(c);
        }
    }

    int ret = 0;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < n; ++j) {
            ret += play(a[i], b[j][i]);
        }
    }

    int best = 0;

    for (int i = 0; i < r; ++i) {
        int z = 0;

        int c = 0;
        for (int j = 0; j < n; ++j) {
            c += play('S', b[j][i]);
        }
        z = max(z, c);

        c = 0;
        for (int j = 0; j < n; ++j) {
            c += play('P', b[j][i]);
        }
        z = max(z, c);

        c = 0;
        for (int j = 0; j < n; ++j) {
            c += play('R', b[j][i]);
        }
        z = max(z, c);

        best += z;
    }

    cout << ret << endl;
    cout << best;
}
