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




void p_3049() {
    //    cin.tie(0);
    //    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    if (n < 4) {
        cout << 0;
    } else {
        cout << (n * (n-1) * (n-2) * (n-3)) / (4 * 3 * 2 * 1);
    }

}
