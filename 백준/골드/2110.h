//
// Created by 임혁 on 24. 8. 07.
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


int N, C;

vector<int> board;


// 가장 인접한 두 공유기의 거리가 주어졌을 때, dis (즉 가장 짧은)
// 설치 가능한 공유기의 개수가 C 개 이상이면 true
// 설치 가능한 공유기의 개수가 C 개 미만이면 false;
// true -> dis 가 더 커도 공유기 C 개를 설치할 가능성이 있지 않을까?
// false -> 현재 dis 에서는 공유기를 C 개 설치하는 것이 불가능 하다. dis 를 더 줄어야 한다.
bool play(const int dis) {
    int cnt = 1; // 설치한 공유기 개수 ( 첫 번째 공유기 )
    int start = 0; // 순서상 가장 뒤에 있는 공유기 인덱스 ( 첫 번째 공유기 )
    for (int i = 1; i < board.size(); ++i) {
        // start 부터 i 까지의 거리가 dis 보다 이상이면 설치 가능하다.
        // dis 가 가장 작다고 가정했기 때문이다.
        if (board[i] - board[start] >= dis) {
            start = i;
            cnt++;
        }
    }
    return cnt >= C;
}

void p_2110() {
    cin >> N >> C;

    board = vector<int>(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    sort(board.begin(), board.end());

    // 최적의 dis 를 설정해야 하는데, 그냥 큰 것 부터 작아 질 때까지 하면 되지 않을까?
    // 가능한 dis 중 가능 큰 값은 당연히 board.back() - board.front();

    /**
     *시간초과
     */

    // 완탐
    // for (int i = board.back() - board.front(); i >= 0; --i) {
    //     if(play(i)) { // 공유기 설치 가능하다면?
    //         // 현재 dis 가 답이다.
    //         cout << i;
    //         return;
    //     }
    // }


    int ret = 1;

    // 절반 씩 줄여나가
    int s = 1; // 공유기 최소 거리 1
    int e = board.back() - board.front(); // 공유기 최대 거리

    while (s <= e) {
        const int dis = (s + e) / 2;
        if (play(dis)) {
            // 공유기 설치 성공!!!
            ret = dis; // 성공했으니까 결과에 저장.
            // dis 가 더 커도 공유기를 더 설치 할 수 있는 가능성을 체크해보자.
            s = dis + 1;
        } else {
            // 공유기 설치 실패!!!
            // dis 가 더 작아야 공유기 설치가 가능하다.
            e = dis - 1;
        }
    }

    cout << ret;
}
