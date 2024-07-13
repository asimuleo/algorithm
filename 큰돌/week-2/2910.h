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
void p_2910() {

	map<int, pair<int, int> > m;

	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		auto it = m.find(n);
		if (it != m.end()) {
			it->second.first++;
		}
		else {
			m.insert(make_pair(n, make_pair(1, i)));
		}
	}

	vector<pair<int, pair<int, int>> > v;
	for (auto &it : m) {
		v.push_back(it);
	}

	sort(v.begin(), v.end(), [](const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> > &p2)->bool
	{
		if (p1.second.first == p2.second.first)
			return p1.second.second < p2.second.second;
		return p1.second.first > p2.second.first;
	}
	);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].second.first; j++)
		{
			cout << v[i].first << ' ';
		}
		
	}

}
