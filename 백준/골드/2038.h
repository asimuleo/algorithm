//
// Created by 임혁 on 24. 8. 05.
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
#include <climits>

using namespace std;

// h 가 y 번 반복됨을 의미한다.
struct hyuk {
    int h;
    int y;
};


/**
* https://metatutor.co.uk/the-golomb-sequence/
* 이걸 보고 golomb 수열이 뭔지 이해해버렸다.
*/
void p_2038() {
    int n;
    cin >> n;
    // 포인터가 n 번째 일 때의 골룸 수열의 수를 구하자.

    if (n <= 2) {
        cout << n;
        return;
    }

    deque<hyuk> golomb_sequence;
    golomb_sequence.push_back({2, 1});

    int total_length = 2;

    int index = 3;

    int ii = 0;

    while (index <= n) {
        hyuk current = golomb_sequence[ii];

        // y 번 만큼 진행
        for (int j = 0; j < current.y; ++j) {
            golomb_sequence.push_back({index, current.h});
            total_length += current.y;
            if (total_length >= n) {
                // 골롬수열에서 y 의 개수가 n 이 되는 지점의 h 를 출력한다.
                int temp = 3;
                golomb_sequence.pop_front();
                if (temp >= n) {
                    cout << golomb_sequence.back().y;
                    return;
                }
                for (auto sequence: golomb_sequence) {
                    temp += sequence.y;
                    if (temp >= n) {
                        cout << sequence.h;
                        return;
                    }
                }
            }
            index++;
        }
        ii++;
    }
}
