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


void p_28432() {


    // 첫 줄에 끝말잇기 기록의 길이 N
    // 후보 단어의 개수 M

    int N, M;
    cin >> N;
    vector<string> strings(N);

    int question_mark_index;

    char front, back;

    // 끝말잊기 보관
    for (int i = 0; i < N; ++i) {
        cin >> strings[i];
        if (strings[i] == "?")
            question_mark_index = i;
    }

    cin >> M;
    vector<string> candidates(M);
    // 후보 보관1
    for (int i = 0; i < M; ++i) {
        cin >> candidates[i];
    }

    if (M == 1) {
        cout << candidates[0];
        return;
    }


    // ? 의 위치에 따라 3가지 경우로 나누기
    if (question_mark_index == 0) {
        back = strings[question_mark_index + 1].front();

        for (int i = 0; i < M; ++i) {
            if (candidates[i].back() == back) {
                // 중복체크
                if (find(strings.begin(), strings.end(), candidates[i]) == strings.end()) {
                    cout << candidates[i];
                    return;
                }
            }
        }

    } else if (question_mark_index == N - 1) {
        front = strings[question_mark_index - 1].back();

        for (int i = 0; i < M; ++i) {
            if (candidates[i].front() == front) {
                // 중복체크
                if (find(strings.begin(), strings.end(), candidates[i]) == strings.end()) {
                    cout << candidates[i];
                    return;
                }
            }
        }

    } else {
        front = strings[question_mark_index - 1].back();
        back = strings[question_mark_index + 1].front();

        for (int i = 0; i < M; ++i) {
            if (candidates[i].front() == front && candidates[i].back() == back) {
                // 중복체크
                if (find(strings.begin(), strings.end(), candidates[i]) == strings.end()) {
                    cout << candidates[i];
                    return;
                }
            }
        }

    }


}