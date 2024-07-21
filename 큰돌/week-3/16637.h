//
// Created by 임혁 on 24. 7. 21.
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

int N;
string s;

vector<int> indexes;

// a b c
int ope(char a, char b, char c) {
    int _a = a - '0';
    int _c = c - '0';

    switch (b) {
        case '+':
            return _a + _c;
        case '-':
            return _a - _c;
        case '*':
            return _a * _c;
    }
}

// a b c
int ope(int a, char b, char c) {
    int _a = a;
    int _c = c - '0';

    switch (b) {
        case '+':
            return _a + _c;
        case '-':
            return _a - _c;
        case '*':
            return _a * _c;
    }
}

// a b c
int ope(int a, char b, int c) {
    int _a = a;
    int _c = c;

    switch (b) {
        case '+':
            return _a + _c;
        case '-':
            return _a - _c;
        case '*':
            return _a * _c;
    }
}


/**
 * 연산 결과의 최대를 반환한다.
 * @param start 연산자
 * @param current 현재까지 결과값
 * @return
 */
int play(int start, int current) {

    if (start == s.size())
        return current;

    if (start == s.size() - 2)
        return play(start + 2, ope(current, s[start], s[start + 1]));


    // current 에 연산을 바로 해버리거나
    // current 에 다음 연산을 묶은걸 연산해버리거나
    return max(play(start + 2, ope(current, s[start], s[start + 1])),
               play(start + 4, ope(current, s[start], ope(s[start + 1], s[start + 2], s[start + 3]))));


}

void p_16637() {

    cin >> N;
    cin >> s;

    cout << play(1, s[0] - '0');

}