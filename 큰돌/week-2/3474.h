//
// Created by cs.javah on 2024. 7. 11.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>

using namespace std;


/**

*/
void p_3473() {

    ios::sync_with_stdio(NULL);
    cin.tie(NULL);


    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;


        int ret = 0;

        int five_r = 5;
        int five_i = 1;

        while (five_r <= n) {

            ret += n / five_r;

            five_i++;
            five_r = five_r * 5;;
        }

        cout << ret << '\n';

    }
}