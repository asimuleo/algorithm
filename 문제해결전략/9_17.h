//
// Created by 임혁 on 2024. 5. 27..
//

/**
 * 코드 9.17 웨브바짐 문제를 해결하는 동적 계획법 알고리즘
 * https://www.algospot.com/judge/problem/read/ZIMBABWE
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1000000007;
// digits: e의 자릿수들을 정렬한 것
string e, digits;
int n, m;
int cache[1 << 14][20][2];


/**
 * 과거 가격을 앞 자리부터 채워나가고 있다.
 * @param index 이번에 채울 자리의 인덱스 (taken 과 중복정보이지만 간편함을 위해)
 * @param taken 지금까지 사용한 자릿수들의 집합 (index 와 역순)
 * @param mod 지금까지 만든 가격의 m에대한 나머지
 * @param less 지금까지 만든 가격이 이미 e보다 작으면 1, 아니면 0
 * @return
 */
int price(int index, int taken, int mod, int less) {
    // 기저 사례
    if (index == n) {
        // e보다 작고, 나머지도 없으면 1
        return (less && mod == 0) ? 1 : 0;
    }
    // 메모이제이션
    int &ret = cache[taken][mod][less];
    if (ret != -1) return ret;
    ret = 0;
    for (int next = 0; next < n; ++next) {
        if ((taken & (1 << next)) == 0) {
            // 과거 가격은 새 가격보다 항상 작아야만 한다.
            // 지금까지 만든 가격이 동일 한데 && next 가 더 크면 = 패스
            if (!less && e[index] < digits[next]) {
                continue;
            }
            // 같은 숫자는 한 번만 선택한다.
            if (next > 0 && digits[next - 1] == digits[next] &&
                (taken & (1 << (next - 1))) == 0) {
                continue;
            }
            int nextToken = taken | (1 << next);
            int nextMod = (mod * 10 + digits[next] - '0') % m;
            int nextLess = less || e[index] > digits[next];
            ret += price(index + 1, nextToken, nextMod, nextLess);
            ret %= MOD;
        }
    }

    return ret;

}