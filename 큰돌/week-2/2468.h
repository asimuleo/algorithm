//
// Created by cs.javah on 2024. 7. 5.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <set>

using namespace std;

int dx[] = { 0, 1, -1, 0 };
int dy[] = { -1, 0, 0, 1 };

int N;

// 모든 board 에 대하여 bfs 로 방문처리 한다.
void bfs(vector<vector<bool>> &visited, int y, int x) {

	queue<pair<int, int>> q;
	q.push({ y, x });

	while (q.size()) {

		pair<int, int> u = q.front();
		q.pop();
		visited[y][x] = true;

		for (int i = 0; i < 4; i++)
		{
			int ny = u.first + dy[i];
			int nx = u.second+ dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visited[ny][nx]) continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;

		}


	}

}

// 비가 height 만큼 올때 안전한 영역의 개수를 반환한다.
int play(vector<vector<int>> &board, int height) {

	vector<vector<bool>> visited(N);
	for (int i = 0; i < N; i++) {
		visited[i] = vector<bool>(N);
		for (int j = 0; j < N; j++) {
			visited[i][j] = (board[i][j] <= height);
		}
	}

	int ret = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(visited, i, j);
				ret++;
			}
		}
	}

	return ret;
}

/*
	첫째 줄에는 어떤 지역을 나타내는 2차원 배열의 행과 열의 개수를 나타내는 N
	둘째줄부터 N*N.

	장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다.
	아무 지역도 물에 잠기지 않을 수도 있다.
*/
void p_2468() {

	cin >> N;

	vector<vector<int>> board(N);
	set<int> s;
	
	for (int i = 0; i < N; i++)
	{
		board[i] = vector<int>(N);
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			s.insert(board[i][j]);
		}
	}

	int ret = 1;

	for (auto it = s.begin(); it != s.end(); it++)
	{
		int height = *it;
		ret = max(ret, play(board, height));
	}

	cout << ret;

}
