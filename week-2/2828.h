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

int N, M, J; // 총 구간, 상자, 사과

int box_left;
int box_right;

// 사과가 주어졌을 때 상자 위치를 옮긴다. 이동한 거리를 반환한다.
int play(int apple) {
	if (apple <= box_left) {
		int w = box_left - apple;
		box_left -= w;
		box_right -= w;
		return w;
	}
	if (box_left < apple && apple < box_right) {
		return 0;
	}
	if (box_right <= apple) {
		int w = apple - box_right;
		box_left += w;
		box_right += w;
		return w;
	}
}


/*
	
*/
void p_2828() {

	
	cin >> N >> M >> J;
	box_left = 1;
	box_right = box_left + M - 1;

	int ret = 0;

	for (int i = 0; i < J; i++)
	{
		int apple;
		cin >> apple;
		ret += play(apple);
	}
	
	cout << ret;

}
