//
// Created by 임혁 on 2024. 7. 4.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

int N, M;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

// bfs 로 목적지 도달시 종료 -> 성공
int play2(vector<vector<int>> miro, vector<vector<int>> visited, int y, int x) {

	queue<pair<int, int>> q;
	q.push({ y, x });
	while (q.size()) { // 비면 종료

		pair<int, int> u = q.front();
		if (u.first == N - 1 && u.second == M - 1) {
			return visited[u.first][u.second];
		}
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = u.first + dy[i];
			int nx = u.second + dx[i];
			if (
				ny >= 0 && ny < N && nx >= 0 && nx < M &&
				!visited[ny][nx] &&
				miro[ny][nx] == 1
				) {
				visited[ny][nx] = visited[u.first][u.second] + 1;
				q.push({ny, nx});
			}
		}
	}
	
	return -1; // 도달 할 리가 없음

}

// 완전탐색 dps 로 하니까 시간초과..
int play(vector<vector<int>> miro, vector<vector<bool>> visited, int y, int x) {
	
	// 기저
	if (y == N - 1 && x == M - 1) {
		return 0;
	}

	int ret = 1000000000;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (
			ny >= 0 && ny < N && nx >= 0 && nx < M && 
			!visited[ny][nx] &&
			miro[ny][nx] == 1
			) {
			visited[ny][nx] = true;
			ret = min(ret, play(miro, visited, ny, nx) + 1);
			visited[ny][nx] = true;
		}
	}

	return ret;

}


/*
	N * M 크기의 배열로 표현되는 미로가 있다.
	1은 이동할 수 있는 칸
	0은 이동할 수 없는 칸
	(1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하시오.
	칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
*/
void p_2178() {
	cin >> N >> M;

	vector<vector<int>> miro(N);
	vector<vector<bool>> visited(N);
	vector<vector<int>> visited2(N);

	for (int i = 0; i < N; i++)
	{
		miro[i] = vector<int>(M);
		visited[i] = vector<bool>(M);
		visited2[i] = vector<int>(M);
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			miro[i][j] = c - '0';
			visited2[i][j] = 0;
		}
	}

	visited[0][0] = true;
	// cout << play(miro, visited, 0, 0) + 1;
	cout << play2(miro, visited2, 0, 0) + 1;


}
