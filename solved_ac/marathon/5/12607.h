//
// Created by cs.javah on 2024. 7. 6.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

int getNum(char c) {
    switch (c) {
        case 'a':
        case 'b':
        case 'c':
            return 2;
        case 'd':
        case 'e':
        case 'f':
            return 3;
        case 'g':
        case 'h':
        case 'i':
            return 4;
        case 'j':
        case 'k':
        case 'l':
            return 5;
        case 'm':
        case 'n':
        case 'o':
            return 6;
        case 'p':
        case 'q':
        case 'r':
        case 's':
            return 7;
        case 't':
        case 'u':
        case 'v':
            return 8;
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            return 9;
        case ' ':
            return 0;
    }
}

int getTime(char c) {
    switch (c) {
        case 'a':
        case 'd':
        case 'g':
        case 'j':
        case 'm':
        case 'p':
        case 't':
        case 'w':
        case ' ':
            return 1;
        case 'b':
        case 'e':
        case 'h':
        case 'k':
        case 'n':
        case 'q':
        case 'u':
        case 'x':
            return 2;
        case 'c':
        case 'f':
        case 'i':
        case 'l':
        case 'o':
        case 'r':
        case 'v':
        case 'y':
            return 3;
        case 's':
        case 'z':
            return 4;
    }
}


void p_12607() {
    int N;
    cin >> N;

    string s;
    getline(cin, s);

    for (int test_case = 1; test_case <= N; ++test_case) {
        string ret;

        getline(cin, s);
        int pre_num = -1;

        for (int i = 0; i < s.size(); ++i) {
            int num = getNum(s[i]);

            if (pre_num == num) {
                ret.append(" ");
            }
            pre_num = num;

            for (int j = 0; j < getTime(s[i]); j++) {
                ret.append(to_string(num));
            }
        }


        cout << "Case #" << test_case << ": " << ret << endl;
    }
}
