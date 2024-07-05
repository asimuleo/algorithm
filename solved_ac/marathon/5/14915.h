//
// Created by cs.javah on 2024. 7. 5.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

/*
	
*/
void p_14915() {

	int m, n;
	cin >> m >> n;

	vector<int> nums;

	while (m >= n) {
		nums.push_back(m%n);
		m = m / n;
	}
	nums.push_back(m%n);

	reverse(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] >= 10)
			cout << char(nums[i] - 10 + 'A');
		else 
			cout << nums[i];
	}

}
