//
// Created by 임혁 on 24. 7. 20.
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
#include <cstring>

using namespace std;

int N, M;

vector<vector<int> > board; // 지도
vector<pair<int, int> > chicken; // 치킨집 위치
vector<pair<int, int> > house; // 집 위치
int chicken_distance[100][13]; // 집과 치킨집의 위치


/**
 * 도시의 최소 치킨 거리를 반환한다.
 * @return 도시의 최소 치킨 거리
 */
int min_chicken_distance() {
    int ret = 0;
    for (int i = 0; i < house.size(); ++i) {
        ret += *min_element(chicken_distance[i], chicken_distance[i] + chicken.size());
    }
    return ret;
}


/**
 * 폐업할 치킨집 을 골라서 도시의 치킨 거리의 최소값을 반환한다.
 * @param start
 * @param selected
 * @return
 */
int play(int start, vector<int> &selected) {

    int ret = 1000000000;

    // 폐업시킬 치킨집을 모두 골랐다면
    if (selected.size() == chicken.size() - M) {

        int temp[house.size()][selected.size()];

        // 선택된 치킨집들의 distance를 모두 3000으로
        for (int i = 0; i < selected.size(); ++i) {
            for (int j = 0; j < house.size(); ++j) {
                temp[j][i] = chicken_distance[j][selected[i]];
                chicken_distance[j][selected[i]] = 3000;
            }
        }
        // 구하기
        int r = min_chicken_distance();
        // 되돌리기
        for (int i = 0; i < selected.size(); ++i) {
            for (int j = 0; j < house.size(); ++j) {
                chicken_distance[j][selected[i]] = temp[j][i];
            }
        }
        return r;
    }

    for (int i = start; i < chicken.size(); ++i) {
        selected.push_back(i);
        ret = min(ret, play(i + 1, selected));
        selected.pop_back();
    }

    return ret;

}

/**
 * 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때
 * 어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는
 */
void p_15686() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M;
    board = vector<vector<int> >(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                chicken.emplace_back(i, j);
            }
            if (board[i][j] == 1) {
                house.emplace_back(i, j);
            }
        }
    }

    // 모든 집과 치킨집의 거리를 구하기
    for (int i = 0; i < house.size(); ++i) {
        for (int j = 0; j < chicken.size(); ++j) {
            int h_y, h_x, c_y, c_x;
            tie(h_y, h_x) = house[i];
            tie(c_y, c_x) = chicken[j];
            chicken_distance[i][j] = abs(h_y - c_y) + abs(h_x - c_x);
        }
    }

    if (chicken.size() == M) { // 폐업을 안시켜도 된다면
        // 도시의 치킨 거리를 출력한다.
        cout << min_chicken_distance();
        return;
    }

    vector<int> selected;
    cout << play(0, selected);

}
