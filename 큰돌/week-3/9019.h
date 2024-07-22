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

int a, b;

int visited[10000]; // 역 추적 및 방문 처리를 위한 배열 ex) visited[3412] = 2341
char command[10000]; // command[2341] = L

char com[] = {'D', 'S', 'L', 'R'};


int way(int w, int u) {
    int d1;
    int d4;
    switch (w) {
        case 0: // D
            return (2 * u) % 10000;
        case 1: // S
            return u == 0 ? 9999 : u - 1;
        case 2: // L
            d1 = u / 1000;
            return (u - d1 * 1000) * 10 + d1;
        case 3: // D
            d4 = u % 10;
            return (u / 10) + (1000 * d4);
    }
}

void bfs() {
    memset(visited, -1, sizeof(visited));
    memset(command, 0, sizeof(command));

    queue<int> q;
    q.push(a);
    visited[a] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int v = way(i, u);

            if (v == b) {
                // 도달 했다면
                command[v] = com[i];
                visited[v] = u;
                return;
            }

            if (visited[v] != -1) continue;
            command[v] = com[i];
            q.push(v);
            visited[v] = u; // 과거 트래킹
        }
    }
}

void play() {
    cin >> a >> b;
    bfs();

    // 트래킹

    vector<char> result;


    int i = b;
    while (true) {
        if (a == i) {
            break;
        }
        result.push_back(command[i]);
        i = visited[i];
    }

    reverse(result.begin(), result.end());
    for (char c: result) {
        cout << c;
    }
    cout << endl;
}

void p_9019() {
    int T;
    cin >> T;

    for (int test_case = 0; test_case < T; ++test_case) {
        play();
    }
}
