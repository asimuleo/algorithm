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
void p_6811() {

    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    int trout, pike, pickerel, total;
    cin >> trout >> pike >> pickerel >> total;

    int ret = 0;

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                if (i == 0 && j == 0 && k == 0) continue;

                if (i * trout + j * pike + k * pickerel <= total) {
                    cout << i << " Brown Trout, " << j << " Northern Pike, " << k << " Yellow Pickerel" << endl;
                    ret++;
                }
            }
        }
    }

    cout << "Number of ways to catch fish: " << ret;

}