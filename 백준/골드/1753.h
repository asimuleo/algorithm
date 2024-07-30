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
    bool visited; // 방문 여부
    vector<pair<int, node *> > *children; // 가중치, 연결된 정점들
};

vector<node *> node_list;

// 정점의 개수, 간선의 개수
int V, E;

// 시작점
int S;


void dijkstra() {
    auto cmp = [](const node *left, const node *right) { return left->distance > right->distance; };
    // 배열 d[V]
    priority_queue<node *, vector<node *>, decltype(cmp)> Q(cmp);

    // 2. 현재 노드를 나타내는 변수 A에 출발 노드의 번호를 저장한다.
    Q.push(node_list[S]);

    while (!Q.empty()) {
        // 3. A로부터 갈 수 있는 임의의 노드 B에 대해, d[A] + P[A][B]와 d[B]의 값을 비교한다.
        // INF와 비교할 경우 무조건 전자가 작다.
        node *A = Q.top();
        Q.pop();

        // 방문 한 곳은 다시 방문하지 않는다.
        // 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 경우, 방문 한 정점이 다시 Q 에서 빠져나올 수 있다.
        if (A->visited == true) {
            continue;
        }

        for (int i = 0; i < A->children->size(); ++i) {
            pair<int, node *> &B = A->children->operator[](i);

            // 이미 방문 된 자식은 비교 대상이 되지 않는다.
            if (B.second->visited == true) {
                continue;
            }

            // 5. A의 모든 이웃 노드 B에 대해 이 작업을 수행한다.
            int &distance = B.second->distance;
            int weight = B.first;

            // 4. 만약 d[A] + P[A][B]의 값이 더 작다면, 즉 더 짧은 경로라면, d[B]의 값을 이 값으로 갱신시킨다.
            if (A->distance + weight < distance) {
                distance = A->distance + weight;
            }

            // 이웃들을 넣어준다.
            Q.push(B.second);
        }

        // 6. A의 상태를 "방문 완료"로 바꾼다. 그러면 이제 더 이상 A는 사용하지 않는다.
        A->visited = true;
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
    vector<vector<pair<int, node *> > > ps(V);
    // 모든 정점을 초기화 해준다.
    for (int i = 0; i < V; ++i) {
        ps[i] = vector<pair<int, node *> >();
        hs[i] = node{i, INT_MAX, false, &ps[i]};
        node_list.push_back(&hs[i]);
    }

    // 첫 시작 정점은 거리가 0이다.
    node_list[S]->distance = 0;

    // 모든 간선을 저장한다.
    for (int i = 0; i < E; ++i) {
        // 거리 저장
        int u, v, w;
        cin >> u >> v >> w;
        node_list[u - 1]->children->emplace_back(w, node_list[v - 1]);
    }

    // 다익스트라
    dijkstra();

    // 모든 정점까지의 거리 출력
    for (int i = 0; i < V; ++i) {
        if (node_list[i]->distance == INT_MAX) {
            cout << "INF" << '\n';
        } else {
            cout << node_list[i]->distance << '\n';
        }
    }
}
