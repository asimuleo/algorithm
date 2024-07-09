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


void plusC(char c, int &y, int &x) {
	if (c == '0') {
		return;
	}
	else if (c == '1') {
		x++;
	}
	else if (c == '2') {
		y++;
	}
	else {
		x++; y++;
	}
	return;
}

/*
	level n contains 4 n different tiles

	Given the quadkey of a tile

	output the zoom level and x and y coordinates of that tile.
*/
void p_11674() {
	string s;
	cin >> s;

	int y = 0;
	int x = 0;

	plusC(s[0], y, x);

	if (s.size() == 1) {
		cout << 1 << ' ' << x << ' ' << y;
		return 0;
	}


	string xx;
	string yy;

	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c == '0') {
			xx.append("0");
			yy.append("0");
		}
		else if (c == '1') {
			xx.append("1");
			yy.append("0");
		}
		else if (c == '2') {
			xx.append("0");
			yy.append("1");
		}
		else {
			xx.append("1");
			yy.append("1");
		}

	}


	int xxx = stoi(xx, nullptr, 2);
	int yyy = stoi(yy, nullptr, 2);

	cout << s.size() << ' ' << xxx << ' ' << yyy;
}
