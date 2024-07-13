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

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string play(string &expression, char ccc) {

    istringstream sst(expression);

    vector<char> a;
    vector<long long> b;

    long long i;
    char c;

    sst >> i;
    b.push_back(i);
    while (1) {
        sst >> c;
        sst >> i;

        if (c == ccc) {
            long long ii = b.back();
            b.pop_back();

            if (c == '+') {
                b.push_back(ii + i);
            } else if (c == '-') {
                b.push_back(ii - i);
            } else {
                b.push_back(ii * i);
            }

        } else {
            a.push_back(c);
            b.push_back(i);
        }
        if (sst.eof() == 1) break;
    }


    string ret = to_string(b[0]);


    for (int j = 0; j < a.size(); j++) {
        string ss(1, a[j]);
        ret.append(ss);
        ret.append(to_string(b[j + 1]));
    }

    return ret;

}


long long solution(string expression) {
    long long answer = 0;

    vector<pair<char, bool>> v{{'+', false},
                               {'-', false},
                               {'*', false}};

    if (expression.find_first_of('+') != string::npos) {
        v[0].second = true;
    }

    if (expression.find_first_of('-') != string::npos) {
        v[1].second = true;
    }

    if (expression.find_first_of('*') != string::npos) {
        v[2].second = true;
    }

    sort(v.begin(), v.end());

    do {

        string str = expression;

        for (auto it2 = v.begin(); it2 != v.end(); ++it2) {
            pair<char, bool> p = *it2;
            if (p.second) {
                if (p.first == '+') {
                    str = play(str, '+');
                } else if (p.first == '-') {
                    str = play(str, '-');
                } else {
                    str = play(str, '*');
                }
            }
        }

        long long l2 = stoll(str);
        answer = max(answer, abs(l2));

    } while (next_permutation(v.begin(), v.end()));


    return answer;
}