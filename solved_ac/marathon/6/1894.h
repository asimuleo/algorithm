//
// Created by 임혁 on 24. 7. 14.
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

using namespace std;

void p_1894() {

    double a, b, c, d, e, f, g, h;

    while (cin >> a) {
        cin >> b >> c >> d >> e >> f >> g >> h;

        if (c == e && d == f) {
            cout << fixed;
            cout.precision(3);
            cout << a + g - e << ' ';
            cout << b + h - f << endl;
        } else if (c == g && d == h) {
            cout << fixed;
            cout.precision(3);
            cout << a + e - g << ' ';
            cout << b + f - h << endl;
        } else if (a == e && b == f) {
            cout << fixed;
            cout.precision(3);
            cout << c + g - e << ' ';
            cout << d + h - f << endl;
        } else {
            cout << fixed;
            cout.precision(3);
            cout << c + e - g << ' ';
            cout << d + f - h << endl;
        }


    }


}