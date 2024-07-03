//
// Created by 임혁 on 2024. 7. 4.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

/*
	재열이가 컵을 섞는 순서가 주어진다. 이 순서는 위 그림에 있는 A,B,C,D,E,F 중 하나이다.
	가강 왼쪽 컵에 작은 공 하나, 가장 오른쪽 컵에 큰 공 하나를 넣어놓았다.

	첫 번째 줄에는 작은 공이 있는 위치를
	두 번째 줄에는 큰 공이 있는 위치를 출력한다.
	공의 위치는 가장 왼쪽부터 1,2,3,4 로표시한다.
*/
void p_13698() {
	
	vector<int> board = { 1, 0, 0, 2 };
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i]) {
		case 'A':
			swap(board[0], board[1]);
			break;
		case 'B':
			swap(board[0], board[2]);
			break;
		case 'C':
			swap(board[0], board[3]);
			break;
		case 'D':
			swap(board[1], board[2]);
			break;
		case 'E':
			swap(board[1], board[3]);
			break;
		default: // F
			swap(board[2], board[3]);
			break;
		}
	}

	cout << find(board.begin(), board.end(), 1) - board.begin() + 1 << endl;
	cout << find(board.begin(), board.end(), 2) - board.begin() + 1 << endl;

}
