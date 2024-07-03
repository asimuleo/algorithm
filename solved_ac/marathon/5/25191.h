//
// Created by 임혁 on 2024. 7. 4.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
	치킨 1마리를 먹을 때 반드시 집에 있는 콜라 2개나 맥주 1개와 같이 먹어야 한다.
	치킨집에 있는 치킨의 개수보다 치킨을 많이 시켜먹을 수는 없다.
	치킨집에 있는 치킨의 개수 N와
	임스의 집에 있는 콜라 A,
	맥주의 개수가 주어졌을 때 B,
	임스가 시켜먹을 수 있는 치킨의 총 개수를 출력

*/
void p_24723() {
	int N;
	cin >> N;
	int A, B;
	cin >> A >> B;

	// 경우의 수는
	// 치킨 1 개에 콜라 2개
	// 치킨 1 개에 맥주 1개
	// 일단 치킨의 개수에서 하나씩 제거할 때마다 
	// 콜라가 있다면 제거,
	// 치킨도 있다면 제거.

	int ret = 0;

	while (N-- > 0) {
		if ((A / 2) > 0) {
			ret++;
			A -= 2;
			continue;
		}
		if (B > 0) {
			ret++;
			B -= 1;
			continue;
		}
	}

	cout << ret;


}
