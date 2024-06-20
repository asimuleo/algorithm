//
// Created by 임혁 on 2024. 6. 17.
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


void p_1296() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);

    string s1;
    cin >> s1;

    int l = 0, o = 0, v = 0, e = 0;
    int t_l = 0, t_o = 0, t_v = 0, t_e = 0;

    for (char c: s1) {
        if (c == 'L') {
            l++;
        } else if (c == 'O') {
            o++;
        } else if (c == 'V') {
            v++;
        } else if (c == 'E') {
            e++;
        }
    }

    int n;
    cin >> n;

    string ss[n];

    int max_ret = -1;
    string max_string;

    for (int i = 0; i < n; ++i) {

        t_l = l;
        t_o = o;
        t_v = v;
        t_e = e;

        cin >> ss[i];

        for (char c: ss[i]) {
            if (c == 'L') {
                l++;
            } else if (c == 'O') {
                o++;
            } else if (c == 'V') {
                v++;
            } else if (c == 'E') {
                e++;
            }
        }

        int score = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100;

        if (max_ret < score) {
            max_ret = score;
            max_string = ss[i];
        }

        if (max_ret == score && max_string > ss[i]) {
            max_string = ss[i];
        }

        l = t_l;
        o = t_o;
        v = t_v;
        e = t_e;

    }

    cout << max_string << endl;


}
