#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

int parent[1001];

int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; // 그래프 수
    cin >> t;

    while (t--) {
        int n; // 그래프 노드 개수
        cin >> n;
        int m; // 그래프 간선 개수
        cin >> m;

        init(n);

        bool isTree = true;

        while (m--) {
            int a, b;
            cin >> a >> b;

            int find_a = find(a);
            int find_b = find(b);
            if (find_a == find_b) {
                isTree = false;
            } else {
                // 내 자신이 부모인 녀석을 기존 트리에 편입시킨다.
                if (find_a == a) {
                    parent[a] = b;
                } else {
                    parent[b] = a;
                }
            }
        }

        if (!isTree) {
            cout << "graph" << '\n';
            continue;
        }

        int f = find(1);
        for (int i = 2; i <= n; i++) {
            if (find(i) != f) {
                cout << "graph" << '\n';
                isTree = false;
                break;
            }
        }

        if (isTree) {
            cout << "tree" << '\n';
        }
    }


    return 0;
}
