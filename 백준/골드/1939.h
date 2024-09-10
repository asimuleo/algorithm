//
// Created by SSAFY on 24. 9. 9.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

int N; // 섬
map<int, int> link[10001]; // 다리
bool visited[10001]; // 방문 여부
int s, e; // 두 공장의 위치


void dijkstra()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        // A번 섬과 B번 섬 사이에 중량제한이 C인 다리
        int A, B;
        int C;
        cin >> A >> B >> C;
        const auto result1 = link[A].insert({B, C});
        if (!result1.second)
        {
            if (C > result1.first->second)
            {
                result1.first->second = C;
            }
        }
        const auto result2 = link[B].insert({A, C});
        if (!result2.second)
        {
            if (C > result2.first->second)
            {
                result2.first->second = C;
            }
        }
    }

    cin >> s >> e;

    int distance[N + 1];
    fill(distance, distance + N + 1, -1);
    distance[s] = 1000000001;

    // 첫 번째 인자가 두 번째 인자보다 앞에 나온다면 true
    // 두번째 인자가 첫번째 인자보다 앞에 나온다면 false
    // > 최소 힙 1 > 2 false greater
    // < 최대 힙 1 < 2 true less
    // queue 에서 가장 마지막에 나온 요소를 얻는 것이 큐의 front(pq top)를 얻는 것이다.
    auto comp = [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
    pq.push({s, 0});
    while (!pq.empty())
    {
        const pair<int, int> u = pq.top();
        pq.pop();
        visited[u.first] = true;
        if (u.first == e)
        {
            cout << distance[e] << endl;
            return;
        }

        for (const auto v : link[u.first])
        {
            if (visited[v.first]) continue;
            int min1 = min(distance[u.first], v.second);
            if (distance[v.first] < min1)
            {
                distance[v.first] = min1;
                pq.push({v.first, distance[v.first]});
            }
        }
    }
}

void graph()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        // A번 섬과 B번 섬 사이에 중량제한이 C인 다리
        int A, B;
        int C;
        cin >> A >> B >> C;
        const auto result1 = link[A].insert({B, C});
        if (!result1.second)
        {
            if (C > result1.first->second)
            {
                result1.first->second = C;
            }
        }
        const auto result2 = link[B].insert({A, C});
        if (!result2.second)
        {
            if (C > result2.first->second)
            {
                result2.first->second = C;
            }
        }
    }

    cin >> s >> e;

    int left = 0;
    int right = 1000000000;
    while (left <= right)
    {
        const int mid = (left + right) / 2; // 최대값
        memset(visited, false, sizeof(visited));
        // bfs 시도
        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            const int u = q.front();
            q.pop();
            if (u == e) break;

            for (auto v : link[u])
            {
                if (visited[v.first]) continue;
                if (v.second < mid) continue;
                q.push(v.first);
                visited[v.first] = true;
            }
        }

        if (visited[e]) // 성공했을시
        {
            left = mid + 1;
        }
        else // 실패 했을 시
        {
            right = mid - 1;
        }
    }
    cout << right;
}

class Kruskal
{
public:
    static vector<int> p;

    static void make(const int n)
    {
        p.assign(n + 1, -1);
    }

    static int find(const int a)
    {
        if (p[a] < 0) return a;
        return p[a] = find(p[a]);
    }

    static bool unite(const int a, const int b)
    {
        const int s1 = find(a);
        const int s2 = find(b);
        if (s1 == s2) return false;
        p[s1] += p[s2];
        p[s2] = s1;
        return true;
    }
};

// 정적 멤버 변수 정의
vector<int> Kruskal::p;

void kruskal()
{
    struct bridge
    {
        int a, b, c;
    };

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> N >> M;

    vector<bridge> bridges;

    for (int i = 0; i < M; ++i)
    {
        // A번 섬과 B번 섬 사이에 중량제한이 C인 다리
        int A, B;
        int C;
        cin >> A >> B >> C;
        bridges.push_back({A, B, C});
    }

    cin >> s >> e;


    sort(bridges.begin(), bridges.end(), [](const bridge& a, const bridge& b) -> bool { return a.c > b.c; });

    // s와 e의 부모가 같으면 종료


    Kruskal::make(N);
    int ret = 0;
    for (bridge b : bridges)
    {
        if (Kruskal::unite(b.a, b.b))
        {
            ret = b.c;
            if (Kruskal::find(s) == Kruskal::find(e))
            {
                cout << ret << endl;
                return;
            }
        }
    }
}

// 한 번의 이동에서 옮길 수 있는 물품들의 중량의 최댓값을 구하는 프로그램을 작성하시오.
int p_1939()
{
    // s로 부터 모든 섬 까지의 중량의 최대값을 구한다.
    // e 를 만나면 그만둔다.
    // dijkstra(); 60 ms

    // 결과값이 될 중량의 최대 값을 미리 정하고 그래프 이론을 도전한다.
    // 미리 정한 결과 값을 이분 탐색으로 줄여나간다.
    // graph(); 100 ms

    // 모든 간선을 내림차순 정렬한 후에
    // 한 간선 씩 union 하면서 s 와 e 가 같은 부모를 가리킬 때 정지
    // MST(Kruskal) 32 ms
    kruskal();

    return 0;
}
