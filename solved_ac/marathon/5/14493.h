//
// Created by cs.javah on 2024. 7. 8.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <set>

using namespace std;

// 현재 시간이 주어졌을때 학인봇의 남은 활동 시간을 반환한다.
// b a b a b a~~
int play(int time, int a, int b) {

	// 처음 활동중일 때
	if (time <= b) {
		return b - time;
	}
	// 처음 휴식기 일때
	if (time < a + b) {
		return 0;
	}

	// 원점
	if (time == a + b) {
		return b;
	}

	return play(time % (a + b), a, b);

}


/*
	A/B 는 해당 구간에서 확인봇이 A초 간격으로 나타나 B 초동안 침입자를 탐지
	각 구간을 통과하는 데에는 1초의 시간이 소요된다.
	구간의 수 N
	학인봇의 활동 정보 
	(a,b) 
	a초 간격 
	b초 동안 활동

	재훈이가 과일노리에 접속하기 위해 필요한 최소 소요시간을 출력한다.
*/
void p_14493() {

	int N;
	cin >> N;

	vector<pair<int, int>> bot(N);

	for (int i = 0; i < N; i++)
	{
		cin >> bot[i].first;
		cin >> bot[i].second;
	}

	int time = 0;

	// 대기 시간만 구하면 된다.
	for (int i = 0; i < N; i++)
	{
		time += play(time, bot[i].first, bot[i].second);
		time++;
	}

	cout << time;

}
