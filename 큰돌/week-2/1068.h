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

struct node {
    int num;
    vector<node *> children;
};

void p_1068() {

    int N;
    cin >> N;
    vector<node> node_list(N);
    int parent_node;

    for (int i = 0; i < N; ++i) {
        node_list[i] = {
                i,
                vector<node *>()
        };
    }

    for (int i = 0; i < N; ++i) {
        int parent;
        cin >> parent;
        if (parent != -1) {
            node_list[parent].children.push_back(&node_list[i]);
        } else {
            parent_node = i;
        }
    }

    int node_to_delete;
    cin >> node_to_delete;

    // 부모를 지우면 끝!
    if (parent_node == node_to_delete) {
        cout << 0;
        return;
    }

    // 지우기
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < node_list[i].children.size(); ++j) {
            if(node_list[i].children[j]->num == node_to_delete) {
                node_list[i].children.erase(node_list[i].children.begin() + j);
            }
        }
    }

    // 찾기
    int leaf = 0;

    // bfs
    queue<node *> q;
    q.push(&node_list[parent_node]);

    while (q.size()) {

        node *u = q.front();
        q.pop();

        if (u->children.empty()) {
            leaf++;
            continue;
        }

        for (int k = 0; k < u->children.size(); k++) {
            node *next_node = u->children[k];
            q.push(next_node);
        }

    }

    cout << leaf;

}