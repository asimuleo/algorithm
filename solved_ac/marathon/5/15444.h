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


void p_15444() {
    int N;
    cin >> N;

    vector<string> n1;
    vector<string> n2;
    vector<string> n3;
    vector<string> n4;
    vector<string> n5;


    string S;
    cin >> S;

    for (int i = 0; i < S.size(); ++i) {
        char c = S[i];
        switch (c) {
            case 'A':
                n1.push_back("***");
                n2.push_back("*.*");
                n3.push_back("***");
                n4.push_back("*.*");
                n5.push_back("*.*");
                break;
            case 'B':
                n1.push_back("***");
                n2.push_back("*.*");
                n3.push_back("***");
                n4.push_back("*.*");
                n5.push_back("***");
                break;
            case 'C':
                n1.push_back("***");
                n2.push_back("*..");
                n3.push_back("*..");
                n4.push_back("*..");
                n5.push_back("***");
                break;
            case 'D':
                n1.push_back("***");
                n2.push_back("*.*");
                n3.push_back("*.*");
                n4.push_back("*.*");
                n5.push_back("***");
                break;
            case 'E':
                n1.push_back("***");
                n2.push_back("*..");
                n3.push_back("***");
                n4.push_back("*..");
                n5.push_back("***");
                break;
            default:
                break;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << n1[i];
    }
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << n2[i];
    }
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << n3[i];
    }
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << n4[i];
    }
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << n5[i];
    }

}
