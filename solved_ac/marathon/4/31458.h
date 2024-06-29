//
// Created by csjav on 24. 6. 29.
//


#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

/**
* 수식은 정수 하나와 0개 이상의 느낌표로 이루어져 있다.
* 정수는 0 또는 1
* 느낌표는 정수의 앞이나 뒤에 올 수 있다.
*
* 0! = 1, 1! = 1
* !0 = 1, !1 = 0
* !n! 과 같이 둘 다 사용된 경우에는 팩토리얼을 먼저 계산
 */
void p_31458() {
    int t;
    cin >> t;
    for (int test_case = 0; test_case < t; ++test_case) {
        string s;
        cin >> s;

        char c;

        int a = 0, b = 0;

        // 거꾸로
        for (auto i = s.rbegin(); i < s.rend(); ++i) {
            if (*i == '!') {
                a++;
            } else {
                c = *i;
                break;
            }
        }

        for (auto i = s.begin(); i < s.end(); ++i) {
            if (*i == '!') {
                b++;
            } else {
                break;
            }
        }

        if (c == '0' && a == 0) {
            c = '0';
        } else {
            c = '1';
        }


        if (c == '0') {
            if (b % 2 == 0) {
                cout << '0' << endl;
            } else {
                cout << '1' << endl;
            }
        } else {
            if (b % 2 == 0) {
                cout << '1' << endl;
            } else {
                cout << '0' << endl;
            }
        }

    }
}
