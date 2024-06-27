//
// Created by csjav on 24. 6. 27.
//


#include <iostream>
#include <cmath>

using namespace std;

void p_25991() {

    int n;
    cin >> n;

    double ret = 0;

    for (int i = 0; i < n; ++i) {
        double d;
        cin >> d;

        ret += d * d * d;
    }

    cout << fixed;
    cout.precision(6);
    cout << cbrt(ret);
}