//
// Created by SSAFY on 24. 9. 19.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, K;

int visited[1000001];

int p_28069()
{
    memset(visited, -1, sizeof(visited));
    cin >> N >> K;

    queue<int> q;
    q.push(0);
    visited[0] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (visited[N] != -1)
        {
            cout << "minigimbob";
            return 0;
        }

        if (visited[u] == K) continue;

        if (u + 1 <= 1000000 && visited[u + 1] == -1)
        {

            visited[u + 1] = visited[u] + 1;
            q.push(u + 1);
        }
        if (u + u / 2 <= 1000000 && visited[u + u / 2] == -1)
        {
            visited[u + u / 2] = visited[u] + 1;
            q.push(u + u / 2);
        }
    }

    cout << "water";


    return 0;
}
