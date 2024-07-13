//
// Created by cs.javah on 2024. 7. 10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

int N;

int dx[] = { 0, 1 };
int dy[] = { 1, 0 };

// n 정사각형이 모두 같은 문자인가요?
bool isAllSame(vector<vector<int> > &board, vector<vector<bool> > &visited, int y, int x, int n) {

	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	int first = board[y][x];

	while (q.size()) {

		pair<int, int> u = q.front();
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			int ny = u.first + dy[i];
			int nx = u.second + dx[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (nx < x || nx >= x + n || ny < y || ny >= y + n) continue;
			if (visited[ny][nx]) continue;
			// 시작 문자와 다르면
			if (board[ny][nx] != first) return false;

			q.push({ ny, nx });
			visited[ny][nx] = true;

		}

	}
	// 모두 시작 문자와 같아요.
	return true;
	
}

void play(vector<vector<int> > &board, vector<vector<bool> > &visited, int y, int x, int n) {
	int fisrt = board[y][x];

	for (int i = y; i < y+n; i++)
		for (int j = x; j < x+n; j++)
			visited[i][j] = false;

	bool same = isAllSame(board, visited, y, x, n);

	if (same) {
		cout << fisrt;
	}
	else {
		cout << '(';
		// Quad
		play(board, visited, y, x, n/2);
		play(board, visited, y, x + n / 2, n / 2);
		play(board, visited, y + n/2, x, n/2);
		play(board, visited, y + n/2, x + n/2, n/2);
		cout << ')';
	}

}


/*
	
*/
void p_1992() {

	cin >> N;

	vector<vector<int> > board(N, vector<int>(N, 0));
	vector<vector<bool> > visited(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c == '1';
		}
	}

	// 시작 칸과 모든칸이 같은지 판단한다.
	play(board, visited, 0, 0, N);

}
