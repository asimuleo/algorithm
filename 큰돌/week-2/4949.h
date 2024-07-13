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
void p_4949() {

    // ios::sync_with_stdio(NULL);
    // cin.tie(NULL);

    while (true) {
        string s;
        getline(cin, s);

        if (s == ".") return;

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            if (s[i] == '[') {
                st.push(s[i]);
            }
            if (s[i] == ')') {
                if (st.empty()) {
                    st.push(s[i]);
                    continue;
                }
                char c = st.top();
                if (c == '(') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
            if (s[i] == ']') {
                if (st.empty()) {
                    st.push(s[i]);
                    continue;
                }
                char c = st.top();
                if (c == '[') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }

        if (st.empty()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

}