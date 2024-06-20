//
// Created by 임혁 on 2024. 5. 28..
//

#include "algorithm"
#include <iostream>
#include <vector>
#include <cmath>
#include "cstring"

using namespace std;

/**
 * 시간이 예상보다 조금 걸린 문제이다. 요금을 계산하는 부분에서 시간이 많이 걸렸다.
 * 시간대 별로 배열을 생성해서 해당 시간에 차량의 개수를 배열에 저장했다.
 * 앞 시간의 수를 a 라고 했고 뒷 시간의 수를 b 라고 했을 때,
 * a 와 b 가 같을 경우에만 처음 생각했던 로직이 통했다.
 * a < b 일 경우 a 만 해당 시간에 이용 한 거고
 * a > b 일 경우에는 b 만 해당 시간에 이용 한 게 된다.
 * 즉 슨 a와 b 중 작은 값이 해당 시간에 이용한 수가 된다.
 */
void p_2979() {

    int price[4];
    price[0] = 0;
    cin >> price[1];
    cin >> price[2];
    cin >> price[3];
    int ret[101];
    memset(ret, 0, sizeof(ret));

    for (int i = 0; i < 3; ++i) {
        int s, e;
        cin >> s >> e;
        for (int j = s; j < e+1; ++j) {
            ret[j]++;
        }
    }

    int sum = 0;

    for (int i = 0; i < 100; ++i) {
        int &a = ret[i];
        int &b = ret[i+1];
        if (a == 0 || b == 0) {
            continue;
        }
        int m = min(a, b);
        sum += price[m] * m;
    }

    cout << sum << endl;
}