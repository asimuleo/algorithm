//
// Created by cs.javah on 2024. 7. 28.
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


// 정점
struct node {
    int position; // 내 번호
    int distance; // 시작점으로부터의 거리
    bool visited;
    vector<pair<int, node *> > children; // 가중치, 연결된 정점들
};

vector<node *> node_list;

// 정점의 개수, 간선의 개수
int V, E;

// 시작점
int S;

auto cmp = [](const node *left, const node *right) { return left->distance > right->distance; };

// S 에서 to 로의 최단 경로의 경로값을 출력한다.
// 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.
void dijkstra() {

    /**
     * 생각해보니까 애초부터 비방문 노드를 Q에 넣어야 하는게 아닌가 하는 생각이 들었다.
     * 이말은 시작부터 모든 노드들을 Q에 넣어놓고 시작해야 한다는 것이다.
     *
     * 라고 생각했는데, 애초에 시작지점으로 도착할 수 없는 아이들이 간선으로 연결되어 있을 경우 그들을 계산해서 버그를 일으키는 것 같다..
     * 자식들만 큐에 넣어주자..
     */

    // 1. 출발점으로부터의 최단거리를 저장할 배열 d[v]를 만들고,
    // 출발 노드에는 0을, 출발점을 제외한 다른 노드들에는 매우 큰 값 INF를 채워 넣는다.
//    int d[V];
//    d[S] = 0;
//    for (int i = 1; i < V; ++i) {
//        d[i] = INT_MAX;
//    }

    // 배열 d[V]
    priority_queue<node *, vector<node *>, decltype(cmp)> Q(cmp);

    // 2. 현재 노드를 나타내는 변수 A에 출발 노드의 번호를 저장한다.
    Q.push(node_list[S]);


    while (!Q.empty()) {
        // 3. A로부터 갈 수 있는 임의의 노드 B에 대해, d[A] + P[A][B]와 d[B]의 값을 비교한다.
        // INF와 비교할 경우 무조건 전자가 작다.
        node *A = Q.top();

        for (auto &B: A->children) {
            // 5. A의 모든 이웃 노드 B에 대해 이 작업을 수행한다.

            int &distance = B.second->distance;
            int weight = B.first;

            // 4. 만약 d[A] + P[A][B]의 값이 더 작다면, 즉 더 짧은 경로라면, d[B]의 값을 이 값으로 갱신시킨다.
            if (A->distance + weight < distance) {
                distance = A->distance + weight;
                // 최단거리를 갱신할 때 우선순위 큐에도 <위치, 거리>의 쌍을 넣어주고,
                // 거리가 가장 짧은 노드를 우선순위 큐를 이용해 고르면 된다.
                if (!B.second->visited)
                    Q.push(B.second);
            }

        }

        // 6. A의 상태를 "방문 완료"로 바꾼다. 그러면 이제 더 이상 A는 사용하지 않는다.
        A->visited = true;
        Q.pop();
        // 7. "미방문" 상태인 모든 노드들 중,
        // 출발점으로부터의 거리가 제일 짧은 노드 하나를 골라서 그 노드를 A에 저장한다.
    }


    // if (d[to] == INT_MAX) {
    //     cout << "INF" << endl;
    // } else {
    //     cout << d[to] << endl;
    // }

    // 8. 도착 노드가 "방문 완료" 상태가 되거나,
    // 혹은 더 이상 미방문 상태의 노드를 선택할 수 없을 때까지, 3~7의 과정을 반복한다.


    for (int i = 0; i < V; ++i) {
        if (node_list[i]->distance == INT_MAX) {
            cout << "INF" << '\n';
        } else {
            cout << node_list[i]->distance << '\n';
        }
    }

}

void p_1753() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    // 입력 부
    cin >> V >> E;
    cin >> S;
    S--;

    vector<node> hs(V);
    // 모든 정점을 초기화 해준다.
    for (int i = 0; i < V; ++i) {
        hs[i] = node{i, INT_MAX, false, vector<pair<int, node *> >()};
        node_list.push_back(&hs[i]);
    }

    // 첫 시작 정점은 거리가 0이다.
    node_list[S]->distance = 0;



    // 모든 간선을 저장한다.
    for (int i = 0; i < E; ++i) {
        // 거리 저장
        int u, v, w;
        cin >> u >> v >> w;

        for (int j = 0; j < node_list[u - 1]->children.size(); ++j) {
            // 간선이 이미 등록되어 있는게 있다면
            if (node_list[u - 1]->children[j].second == node_list[v - 1]) {
                // 새로운 간선의 가중치가 더 작다면
                if (node_list[u - 1]->children[j].first > w) {
                    node_list[u - 1]->children[j].first = w;
                    break;
                }
            }
        }

        node_list[u - 1]->children.emplace_back(w, node_list[v - 1]);

    }

    // 다익스트라
    dijkstra();

}


// 6 9
// 1
// 1 2 10
// 1 3 30
// 1 4 15
// 2 5 20
// 5 6 20
// 3 6 5
// 6 4 20
// 4 6 20
// 4 3 5