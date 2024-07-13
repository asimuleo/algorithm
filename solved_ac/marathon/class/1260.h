//
// Created by 임혁 on 2024. 6. 5..
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>

using namespace std;


void dfs(int x, const vector<vector<int>> &graph, bool *visited) {// 현재 노드 방문 처리
    visited[x] = true;
    cout << x << ' ';
    // 그와 연결된 방문하지 않은 노드를 발견할 때마다 재귀호출
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) dfs(y, graph, visited);
    }
}

void bfs(int start, const vector<vector<int>> &graph, bool *visited) {

    queue<int> q;

    // 현재 노드 방문 처리
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        // 큐의 앞의 원소를 하나씩 뽑아서 진행
        int x = q.front();
        q.pop();
        cout << x << ' ';

        // 연결된, 아직 방문하지 않은 노드 모두 방문
        for (int i = 0; i < graph[x].size(); ++i) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }


}


void p_1260() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);


    // 정점의 개수 N(1 ≤ N ≤ 1,000),
    // 간선의 개수 M(1 ≤ M ≤ 10,000),
    // 탐색을 시작할 정점의 번호 V

    int n, m, v;
    cin >> n >> m >> v;

    // 정점의 개수만큼 간선을 저장할 벡터를 만든다.
    vector<vector<int>> graph(n + 1, vector<int>(0));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // 작은 것을 먼저 방문해야 하기 때문에 정렬이 필요
    for (int i = 1; i < n + 1; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }
    bool visited[n + 1];
    memset(visited, 0, sizeof(visited));
    dfs(v, graph, visited);
    cout << endl;
    memset(visited, 0, sizeof(visited));
    bfs(v, graph, visited);


}
