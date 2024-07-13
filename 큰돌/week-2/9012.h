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
#include <stack>

using namespace std;


/**

*/
void p_9012() {

    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        stack<int> st;

        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++) {

            if (st.empty()) {
                st.push(s[i]);
                continue;
            }

            int a = st.top();

            if (s[i] == ')' && a == '(') {
                st.pop();
            } else {
                st.push(s[i]);
            }

        }

        if (st.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }


}