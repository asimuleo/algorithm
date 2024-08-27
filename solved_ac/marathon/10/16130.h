//
// Created by 임혁 on 24. 8. 13.
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

void p_16130() {

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;

        int ret = 0;
        int acc = 0;
        int mok = 0;

        for (auto &c: s) {
            int minus;
            if (isdigit(c)) {
                minus = c - '0';
            } else {
                minus = c - 'A' + 10;
            }

            acc = acc + minus;
            if (mok < acc / 10) {
                if (acc / 10 >= 1 && acc / 10 <= 3) {
                    ret += acc / 10;
                } else if (acc / 10 == 4) {

                } else if (acc / 10 > 4) {

                }
            }


            mok = acc / 10;
        }
    }

}