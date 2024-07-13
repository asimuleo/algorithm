//
// Created by 임혁 on 2024. 5. 23..
//

/**
 * 코드 9.15 여행하는 외판원 문제를 해결하는 동적 계획법 알고리즘
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 10

int n, dist[MAX][MAX]; // 도시 n 최대 10
double cache[MAX][1 << MAX]; // -1로 초기화 해 둔다.

void input() {
    n = 3;
    cout << "도시의 수 : " << n << endl;
    cout << "경로" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = random() % 11;
            if (i != j)
                cout << "dist[" << i << "][" << j << "] = " << dist[i][j] << endl;
        }
    }
}


void init_cache() {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < (1 << MAX); ++j) {
            cache[i][j] = -1;
        }
    }
}

/**
 * here: 현재 위치
 * visited: 각 도시의 방문 여부
 * here에서 시작해 남은 도시들을 방문할 수 있는 최단 경로의 길이를 반환한다.
 * 나저미 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환한다.
 * 항상 0번 도시에서 시작한다고 가정한다.
 */
double shortestPath2(int here, int visited) {
    // 기저 사례: 모든 도시를 다 방문했을 때는 0번 도시러 돌아가고 종료한다.
    if (visited == (1 << n) - 1) return dist[here][0];
    // 메모이제이션
    double &ret = cache[here][visited];
    if (ret >= 0) return ret;
    ret = INFINITY; // 매우 큰 값으로 초기화
    // 다음 방문할 도시를 전부 시도해 본다.
    for (int next = 0; next < n; ++next) {
        // 이미 방문한 도시인 경우
        if (visited & (1 << next)) continue;
        double cand = dist[here][next] +
                      shortestPath2(next, visited + (1 << next));
        ret = min(ret, cand);
    }
    return ret;
}

void test_9_15() {
    input();
    init_cache();
    cout << shortestPath2(0, 1) << endl;
}