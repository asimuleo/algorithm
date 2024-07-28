//
// Created by 임혁 on 24. 7. 28.
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
#include <cstring>

using namespace std;


int ope(int a, char c, int b) {
    switch (c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return a % b;
    }
}


void p_26577() {

    int n; // number of data sets
    cin >> n;

    // only operators will be + - * / %

    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);

        deque<int> nums;
        deque<char> opes;

        istringstream iss(s);

        int num;
        iss >> num;
        nums.push_back(num);

        while (!iss.eof()) {
            char c;
            iss >> c;
            opes.push_back(c);
            iss >> num;

            // 연산자 우선순위가 높은 것은 먼저 해버리기
            if (opes.back() == '*' || opes.back() == '/' || opes.back() == '%') {
                int new_i = ope(nums.back(), opes.back(), num);
                nums.pop_back();
                opes.pop_back();
                nums.push_back(new_i);
            } else {
                nums.push_back(num);
            }
        }


        while(!opes.empty()) {
            int a = nums.front();
            nums.pop_front();
            int b = nums.front();
            nums.pop_front();
            char c = opes.front();
            opes.pop_front();

            nums.push_front(ope(a, c, b));
        }

        cout << nums.back() << endl;

    }


}