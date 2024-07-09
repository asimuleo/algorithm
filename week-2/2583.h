//
// Created by cs.javah on 2024. 7. 9.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <set>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int M, N, K; // M 이 세로

// bfs 로 탐색한 넓이를 반환한다.
int bfs(vector<vector<bool> > &board, int y, int x) {

	int ret = 1;

	queue<pair<int, int>> q;

	q.push({ y, x });
	board[y][x] = true;

	while (q.size()) {

		pair<int, int> u = q.front();
		q.pop();
		// 모든 인접한 v 를 q에 넣는다.
		for (int i = 0; i < 4; i++)
		{
			int ny = u.first + dy[i];
			int nx = u.second + dx[i];
			if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
			if (board[ny][nx]) continue;
			q.push({ ny, nx });
			board[ny][nx] = true;
			ret++;
		}

	}

	return ret;
}



/*
	K개의 직사각형
	M×N(M,N≤100)크기의 모눈종이

	K개의 직사각형 내부를 제외한 나머지 부분이
	몇 개의 분리된 영역으로 나누어지는지
	분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력


	대충 직사각형에 해당하는 부분은 다 칠하고, 모든 구간에 대해 dfs 또는 bfs 를 하면 되겠다.
*/
void p_2583() {


	cin >> M >> N >> K;
	vector<vector<bool>> board(M, vector<bool>(N, false));
	
	// 직사각형 채우기
	for (int i = 0; i < K; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = b; j < d; j++)
		{
			for (int k = a; k < c; k++)
			{
				board[j][k] = true;
			}
		}
	}

	// 분리된 각 영역의 넓이
	vector<int> ret;

	// 모든 영역에 대하여
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j]) continue;
			ret.push_back(bfs(board, i, j));
		}
	}

	cout << ret.size() << endl;
	sort(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << ' ';
	}


}
