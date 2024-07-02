//
// Created by csjav on 24. 7. 2.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void p_2358() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int ret = 0;

	// y 축 평행
	for (int i = 0; i < n; i++)
	{
		int next = i + 1;
		while (next < n && x[next-1] == x[next]) {
			next += 1;
		}
		if (next != i + 1) {
			ret += 1;
			i = next - 1;
		}
	}

	// x 축 평행
	for (int i = 0; i < n; i++)
	{
		int next = i + 1;
		while (next < n && y[next - 1] == y[next]) {
			next += 1;
		}
		if (next != i + 1) {
			ret += 1;
			i = next - 1;
		}
	}


	cout << ret;
}
