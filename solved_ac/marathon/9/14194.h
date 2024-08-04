//
// Created by csjav on 24. 8. 4.
//

#include <cstdio>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

void p_14194() {
    int T;
    cin >> T;
    for (int test_case = 0; test_case < T; ++test_case) {
        int n;
        cin >> n;
        vector<double> grades(n);
        for (int i = 0; i < n; ++i) {
            cin >> grades[i];
        }
        sort(grades.begin(), grades.end());
        double A = (grades.front() + grades.back()) / 2;

        double sum = 0;
        for (auto grade: grades) {
            sum += grade;
        }

        double B = sum / grades.size();

        if (abs(A - B) < 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
