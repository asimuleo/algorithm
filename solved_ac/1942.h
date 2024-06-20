//
// Created by 임혁 on 2024. 6. 16..
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


void p_1942() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);


    for (int test_case = 0; test_case < 3; ++test_case) {

        string c1, c2;
        cin >> c1 >> c2;

        int ret = 0;

        int h1 = stoi(c1.substr(0, 2));
        int h2 = stoi(c2.substr(0, 2));

        int s1 = stoi(c1.substr(6, 2));
        int s2 = stoi(c2.substr(6, 2));

        int m1 = stoi(c1.substr(3, 2));
        int m2 = stoi(c2.substr(3, 2));

        if ((h1 * 10000 + m1 * 100 + s1) % 3 == 0) {
            ret++;
        }


        while (!(h1 == h2 && s1 == s2 && m1 == m2)) {

            s1++;

            if (s1 == 60) {
                s1 = 0;
                m1 = m1 + 1;
                if (m1 == 60) {
                    m1 = 0;
                    h1 = h1 + 1;
                    if (h1 == 24) {
                        h1 = 0;
                    }
                }
            }

            if ((h1 * 10000 + m1 * 100 + s1) % 3 == 0) {
                ret++;
            }

        }


        cout << ret << endl;

    }
}
