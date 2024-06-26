//
// Created by 임혁 on 2024. 6. 1..
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;



// 나머지를 계산하는 함수
int na_meo_ji(int a, int b, int c) {

    if (b == 1UL) {
        return a % c;
    }

    unsigned long pre = na_meo_ji(a, b / 2, c);

    if (b % 2 == 1) {
        return pre * pre % c * a % c;
    } else {
        return pre * pre % c;
    }


}

/**⁄
 * 설명이 필요 없다.
 */
void p_1629() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;
    cout << na_meo_ji(a, b, c);

}

/**
* 이 문제는 진짜 하루 종일 생각한 것 같다.
 * 처음에 문제를 봤을 떄는 a, b ,c 가 일단 int 양수 범위의 끝 까지 될 수 있다고 하길래,
 * a 를 c 로 지속적으로 나눠 가면서 b 면 제곱하면 int 를 오버플로우 하는 일은 없다는 생각을 하고선
 * 가볍게 논리 그대로 구현을 했다. 반복문을 돌면서 a 를 b 번 제곱했다. 하지만 시간 초과 였다.
 *
 * 다음에 생각한 것은 나머지라는게 반복될 수 도 있다는 점에서 착안했다.
 * 첫번째 시도와 다르지 않지만 중간에 나머지의 반복이 발견되면 빠르게 중단하게끔 로직을 작성하여 시간을 줄여보려고 했다.
 * 하지만 메모리 초과 그리고 정답 자체가 틀릴 때도 있었다.
 * 그 이유를 지금 생각해 보면 애초에 어떤 수의 나머지의 반복을 찾아내는 것이 어렵고,
 * ( 나는 첫번째 나머지가 다음번에 등장하면, 첫번째 부터 다음번 까지를 반복 구간이라 생각했다. )
 * ( 또 다른 것은 다음번이 그다음번과 동일 할 때 이다. 1 3 3 3 3  같이. )
 * 어떤 수는 애초에 나머지가 반복되지 않을 수도 있다는 것이다. -> 메모리 초과
 *
 * 마지막으로 생각한 것은 절반으로 나누는 것이였다. 이 방법을 떠오르게 된 계기는 직접 손으로 8 4 27 을 구하면서 떠올렸다.
 * 8 4 27의 정답은 19 인데, 64 2 27 의 정답도 19 이고 4096 1 27 의 정답도 19이다.
 * 하고 싶은 애기는 64를 27로 나눈 나머지의 10을 제곱한 100을 27 로 나눠도 19이라는 것이다.
 * 즉 나머지들의 곱셈도 허용 된다는 것이였다.
 * 그렇기 때문에 (a, b, c) 의 결과를 a^b mod c 라고 했을때,
 * (a, b, c) = (a, b/2, c) * (a, b/2, c) % c
 * (8*8*8*8 mod 27) = (8*8 mod 27) * (8*8 mod 27) % 27
 *                  = (64 mod 27) * (64 mod 27) % 27
 * 가 성립한다.
 * 점화식이 완성됬으니 재귀함수를 작성하면 끝이다. b 가 홀수인 경우도 포함해서 점호식을 작성하자.
 * 마지막으로 주의할 것은 중간 과정의 나머지들의 곱셈은 int 를 넘어설 수 있기에 더 큰 범위인 unsigned long 을 사용했다.
*/