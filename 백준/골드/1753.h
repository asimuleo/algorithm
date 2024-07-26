//
// Created by cs.javah on 2024. 7. 23.
//

#include <cstdio>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>

using namespace std;


struct hyuk {
    int position;
    vector<pair<int, hyuk *> > children;
};

vector<hyuk> hyuks;

struct node {
    int position; // 위치
    int distance; // 시작점으로부터 거리
};

// 정점의 개수, 간선의 개수
int V, E;

// 시작점
int S;


// S 에서 to 로의 최단 경로의 경로값을 출력한다.
// 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.
void dijkstra() {
    bool visited[V] = {false};

    auto cmp = [](const node left, const node right) { return left.distance > right.distance; };

    // 1. 출발점으로부터의 최단거리를 저장할 배열 d[v]를 만들고,
    // 출발 노드에는 0을, 출발점을 제외한 다른 노드들에는 매우 큰 값 INF를 채워 넣는다.
    int d[V];
    d[S] = 0;
    for (int i = 1; i < V; ++i) {
        d[i] = INT_MAX;
    }

    // 2. 현재 노드를 나타내는 변수 A에 출발 노드의 번호를 저장한다.
    int A = S;

    priority_queue<node, std::vector<node>, decltype(cmp)> Q(cmp);

    while (true) {
        // 3. A로부터 갈 수 있는 임의의 노드 B에 대해, d[A] + P[A][B]와 d[B]의 값을 비교한다.
        // INF와 비교할 경우 무조건 전자가 작다.

        for (int B = 0; B < hyuks[A].children.size(); B++) {
            // 5. A의 모든 이웃 노드 B에 대해 이 작업을 수행한다.

            int position = hyuks[A].children[B].second->position;
            int weight = hyuks[A].children[B].first;

            // 4. 만약 d[A] + P[A][B]의 값이 더 작다면, 즉 더 짧은 경로라면, d[B]의 값을 이 값으로 갱신시킨다.
            if (d[A] + weight < d[position]) {
                d[position] = weight + d[A];
                // 최단거리를 갱신할 때 우선순위 큐에도 <위치, 거리>의 쌍을 넣어주고,
                // 거리가 가장 짧은 노드를 우선순위 큐를 이용해 고르면 된다.
                if (!visited[position])
                    Q.push(node{position, d[position]});
            }
        }

        // 6. A의 상태를 "방문 완료"로 바꾼다. 그러면 이제 더 이상 A는 사용하지 않는다.
        visited[A] = true;
        // 7. "미방문" 상태인 모든 노드들 중,
        // 출발점으로부터의 거리가 제일 짧은 노드 하나를 골라서 그 노드를 A에 저장한다.
        if (Q.empty()) {
            break;
        }

        A = Q.top().position;
        Q.pop();
    }


    // if (d[to] == INT_MAX) {
    //     cout << "INF" << endl;
    // } else {
    //     cout << d[to] << endl;
    // }

    // 8. 도착 노드가 "방문 완료" 상태가 되거나,
    // 혹은 더 이상 미방문 상태의 노드를 선택할 수 없을 때까지, 3~7의 과정을 반복한다.


    for (int i = 0; i < V; ++i) {
        if (d[i] == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << d[i] << endl;
        }
    }
}

void p_1753() {
    cin >> V >> E;
    cin >> S;
    S--;

    hyuks = vector<hyuk>(V);

    for (int i = 0; i < V; ++i) {
        hyuks[i].position = i;
        hyuks[i].children = vector<pair<int, hyuk *> >();
    }

    for (int i = 0; i < E; ++i) {
        // 거리 저장
        int u, v, w;
        cin >> u >> v >> w;
        hyuks[u - 1].children.emplace_back(w, &hyuks[v - 1]);
    }

    // 다익스트라
    dijkstra();


    // // V 번 출력해야 한다.
    // for (int i = 0; i < V; ++i) {
    //     // S 부터 i 번 정점으로의 최단 경로를 출력한다.
    //     dijkstra(i);
    // }
}
