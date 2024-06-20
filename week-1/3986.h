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

/**⁄
 * 설명이 필요 없다.
 */
void p_3986() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);


    int n; // 단어의 수 n = 1 ~ 100
    cin >> n;

    int ret = 0;

    for (int i = 0; i < n; ++i) {
        string s; // 단어  2 ~ 100,000
        cin >> s;

        /**
         * 좋은 단어라면 바로 옆에 붙은 쌍을 계속 지워나가게 되면 결국 문자열 자체가 없어질 것이다.
         * 없어지지 않는다면 좋은 단어가 아니다.
         * 문자열을 반복문을 j 로 돈다.
         * 못 지워나간 쌍을 vector 에 push 한다.
         * 지웠다면 j = j + 1 이다.
         * 못지나간 쌍의 크기가 0이라면 좋은 단어이다.
         */
        vector<char> leavings;

        for (int j = 0; j < s.size(); ++j) {
            if (leavings.empty()) {
                if (s[j] == s[j + 1]) {
                    j = j + 1;
                    continue;
                }
            } else {
                if (s[j] == leavings.back()) {
                    leavings.pop_back();
                    continue;
                }
            }
            leavings.push_back(s[j]);
        }

        if (leavings.empty()) {
            ret++;
        }

    }

    cout << ret;


}