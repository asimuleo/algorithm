//
// Created by cs.javah on 2024. 7. 10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>

using namespace std;


/*
	
*/
void p_2870() {
	int N;
	cin >> N;

	vector<string> nums;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;



		for (int j = 0; j < s.size(); j++)
		{
			string number;

			if (!isdigit(s[j])) continue;

			number.append(to_string(s[j] - '0'));
			j++;
			while (j < s.size() && isdigit(s[j])) { // 숫자일때까지
				number.append(to_string(s[j] - '0'));
				j++;
			}

			size_t it = number.find_first_not_of('0');
			if (it != string::npos) {
				nums.push_back(number.substr(it));
			}
			else {
				nums.push_back("0");
			}

			

		}

	}

	sort(nums.begin(), nums.end());
	stable_sort(nums.begin(), nums.end(), [](const string &a, const string &b)->bool { return a.size() < b.size(); });

	for (int j = 0; j < nums.size(); j++)
	{
		cout << nums[j] << endl;
	}
}
