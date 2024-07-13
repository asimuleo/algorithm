//
// Created by cs.javah on 2024. 7. 12.
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

/**

*/
void p_5063() {

    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int r, e, c;
        cin >> r >> e >> c;

        if (e - r > c)
            cout << "advertise" << endl;
        else if (e - r == c)
            cout << "does not matter" << endl;
        else
            cout << "do not advertise" << endl;
    }

}