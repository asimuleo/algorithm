//
// Created by SSAFY on 24. 8. 27.
//

#include "iostream"
#include "vector"
#include "queue"
#include "cstring"

using namespace std;

int p_2252() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 학생의 수
    cin >> N;
    int M; // 키를 비교한 횟수
    cin >> M;


    int in_degree[N + 1]; // 진입 차수
    memset(in_degree, 0, sizeof(in_degree));
    vector<int> students[N + 1]; // 인접 리스트

    for (int i = 0; i < M; ++i) {
        int a, b; // 두 학생의 번호
        cin >> a >> b; // 학생 A가 학생 B의 앞에 서야 한다
        in_degree[b]++;
        students[a].push_back(b);
    }


    queue<int> q;
    // 진입 차수가 0인 모든 q 를 넣는다.
    for (int i = 1; i < N + 1; ++i) {
        if (!in_degree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_degree[u]--;

        cout << u << ' ';

        for (int student: students[u]) {
            // 인전합 정점의 모든 진입 차수를 감소
            in_degree[student]--;
            if (in_degree[student] == 0) {
                // 진입 차수가 0인 모든 q 를 넣는다.
                q.push(student);
            }
        }
    }

    return 0;
}
