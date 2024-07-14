//
// Created by 임혁 on 24. 7. 13.
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


// B trusted 에다가 A 넣기
struct computer {
    int num;
    vector<computer *> trusted;
};


// 해당 컴퓨터가 해킹되었을 시 해킹되는 컴퓨터의 수를 반환한다.
int hack(vector<computer> &computer_list, vector<bool> &visited, vector<int> &hacked, int num) {

    if (computer_list[num].trusted.empty()) {
        return 1;
    }

    int &ret = hacked[num];

    if (ret != -1)
        return ret;

    visited[num] = true;

    int sum = 1;

    // 신뢰하는 컴퓨터들
    for (int i = 0; i < computer_list[num].trusted.size(); ++i) {
        if (visited[computer_list[num].trusted[i]->num]) continue;
        sum += hack(computer_list, visited, hacked, computer_list[num].trusted[i]->num);
    }

    return ret = sum;
}

void p_1325() {

    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<computer> computer_list(N);

    for (int i = 0; i < N; ++i) {
        computer_list[i] = {
                i,
                vector<computer *>()
        };
    }

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        computer_list[b - 1].trusted.push_back(&computer_list[a - 1]);
    }

    vector<int> hacked(N, -1);

    int max_hacked = 1;

    for (int i = 0; i < N; ++i) {
        vector<bool> visited(N, false);
        hacked[i] = hack(computer_list, visited, hacked, i);
        max_hacked = max(max_hacked, hacked[i]);

    }

    vector<int> max_hacked_computer;

    for (int i = 0; i < N; ++i) {
        if (hacked[i] == max_hacked) {
            max_hacked_computer.push_back(i);
        }
    }

    sort(max_hacked_computer.begin(), max_hacked_computer.end());

    for (int i = 0; i < max_hacked_computer.size(); ++i) {
        cout << max_hacked_computer[i] + 1 << ' ';
    }


}
