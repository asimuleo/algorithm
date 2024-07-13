//
// Created by cs.javah on 2024. 7. 11.
//

#include <cstdio>
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
void p_1436() {

    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    int n;
    cin >> n;

    int nums = 0;

    int num = 666;

    while (nums != n) {
        if (to_string(num).find("666") != string::npos) {
            nums++;
            num++;
        } else {
            num++;
        }

    }


    cout << --num;


}