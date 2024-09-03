//
// Created by SSAFY on 24. 9. 3.
//

#include <iostream>
#include <queue>
#include <cstring>


using namespace std;

int p_1463() {
    int N;
    cin >> N;

    bool visited[N + 1];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(N);
    visited[N] = true;
    int ret = 0;
    while (!q.empty()) {
        int size = q.size();

        queue<int> temp;

        for (int i = 0; i < size; i++) {
            int u = q.front();
            if (u == 1) {
                cout << ret;
                return 0;
            }
            q.pop();

            if (u % 3 == 0 && !visited[u / 3]) {
                visited[u / 3] = true;
                temp.push(u / 3);
            }

            if (u % 2 == 0 && !visited[u / 2]) {
                visited[u / 2] = true;
                temp.push(u / 2);
            }
            if (!visited[u - 1]) {
                visited[u - 1] = true;
                temp.push(u - 1);
            }
        }
        ret++;
        q = temp;
    }
}
