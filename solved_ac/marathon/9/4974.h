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

void p_4974() {
    int n;
    cin >> n;
    while (n != 0) {
        vector<int> scores(n);
        for (int i = 0; i < n; ++i) {
            cin >> scores[i];
        }
        sort(scores.begin(), scores.end());

        int sum = 0;

        for (int i = 1; i < scores.size() -1; ++i) {
            sum += scores[i];
        }

        cout << sum / (scores.size() - 2) << endl;

        cin >> n;
    }
}
