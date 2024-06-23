//
// Created by 임혁 on 2024. 6. 23.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <iomanip>
#include <list>


using namespace std;


void p_25305() {
    //    cin.tie(0);
    //    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }
    sort(scores.begin(), scores.end());



    while (k-- > 1) {
        scores.pop_back();
    }

    cout << *(scores.end()-1);


}
