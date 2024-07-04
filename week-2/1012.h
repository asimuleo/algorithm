//
// Created by cs.javah on 2024. 7. 4.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int M, N, K;

// 현재 정점에 대한 bfs 탐색으로 상하좌우로 연결된 모든 배추를 방문처리 한다.
void bfs(vector<vector<bool> > &board, vector<vector<bool> > &visited, int y, int x) {

	queue<pair<int, int>> q;
	
	q.push({y, x});
	visited[y][x] = true;

	while (q.size()) {

		// 일단 뽑는다.
		pair<int, int> u = q.front();
		q.pop();

		// 모든 후보에 대해 큐에 넣는다.
		for (int i = 0; i < 4; i++)
		{

			int ny = u.first + dy[i];
			int nx = u.second + dx[i];

			// 범위 벗어나면 제외
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			// 이미 방문한것은 제외
			if (visited[ny][nx]) continue;
			// 배추만 간다.
			if (!board[ny][nx]) continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;

		}

	}


}


// 필요한 최소의 배추흰지렁이 마리 수를 반한한다.
int play(vector<vector<bool> > &board, vector<vector<bool> > &visited) {

	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// 배추가 심어져 있고, 방문한 적이 없다면
			if (board[i][j] && !visited[i][j]) {
				ret++;
				bfs(board, visited, i, j);
			}
		}
	}

	return ret;

}


/*
	첫 줄에는 테스트 케이스 개수 T 가 주어진다.
	각각의 테스트 케이스에 대해 
	첫째 줄에는 배추를 심은 배추밭의 가로길이 M과 세로길이 N, 그리고 배추 개수 K
	그 다음 K 줄에는 배추의 위치 X, Y 가 주어진다.
	
	각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.


	// visited 를 두고 모든 위치에 대해 반복을 돌면서 bfs 가 가능한 개수 를 출력
*/
void p_1012() {

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
	
		cin >> M >> N >> K;


		vector<vector<bool> > board(N);
		vector<vector<bool> > visited(N);
		for (int i = 0; i < N; i++)
		{
			board[i] = vector<bool>(M);
			visited[i] = vector<bool>(M);
			for (int j = 0; j < M; j++)
			{
				board[i][j] = false;
				visited[i][j] = false;
			}
		}
		// 입력을 board로
		for (int k = 0; k < K; k++)
		{
			int x, y;
			cin >> x >> y;
			board[y][x] = true;
		}


		cout << play(board, visited) << endl;

	}

}
