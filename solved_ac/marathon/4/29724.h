//
// Created by csjav on 24. 7. 1.
//


#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

/**
* 가로, 높이, 세로 12cm 정육면체 모양으로, 질량 500g 으로 일정하고, 포장 또한 질량 1,000g 짜리 특수 제작 상자
* 배즙 상자에는 크기와 상관 없이 120g 짜리 배즙 50개씩 들어있다고 계산
*
* 상자의 개수 N
*
* T는 사과를 나타내는 A와 배(Bae)를 나타내는 B로만 구성된다.
* 상자의 가로, 높이, 세로를 나타내는 세 정수 W,H,L로 구성 (cm 단위)
*
*
* 첫 번째 줄에 문을 막고 있는 상자의 질량을 g 단위 출력
* 두 번째 줄에 사과의 값어치가 얼마인지를 시장 사과 가격(원)으로 단순히 계산하여 출력
*/
void p_29724() {
    int n; // 상자의 개수
    cin >> n;

    int ret_g = 0;
    int apple = 0;

    for (int i = 0; i < n; ++i) {
        char T; // 사과, 배
        cin >> T;
        int W, H, L; // 가로, 높이, 세로
        cin >> W >> H >> L;

        if (T == 'A') {
            // 사과라면
            int w = 0, h = 0, l = 0; // 각각 가로, 높이, 세로 에 사과가 몇개 들어가는지
            while (12 * ++w <= W) {}
            while (12 * ++h <= H) {}
            while (12 * ++l <= L) {}
            w--; h--; l--;
            int total_apple = w * h * l;
            apple += total_apple;
            ret_g += total_apple * 500 + 1000;

        } else {
            // 배 라면
            ret_g += 6000;
        }

    }

    cout << ret_g << endl;
    cout << apple * 4000 << endl;
}
