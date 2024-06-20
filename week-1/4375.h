//
// Created by 임혁 on 2024. 6. 3..
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

/**⁄
 * 설명이 필요 없다.
 */
void p_4375() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    int n; // 2와 5로 나누어 떨어지지 않는 정수 1 ~ 10,000

    while (cin >> n) {

        // 각 자릿수가 모두 1로만 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다.
//        1
//        11
//        111
//        1111
//        11111

        // 나머지라는게 0이 될때까지 계속 넘기면 되는거 아님?


        int ret = 1;

        int na_meo_ji = 1 % n;

        while (na_meo_ji != 0) {

            na_meo_ji = (na_meo_ji * 10 + 1) % n;
            ret++;

        }

        cout << ret << endl;

    }



}

