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


bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

/*
	
*/
void p_4659() {

	string s;
	cin >> s;
	while (s != "end") {

		bool acceptable = true;

		bool hasVowel = false;
		int pp_eum = -1, p_eum = -1; // 자음 0. 모음 1
		char p_char = ' ';
		
		for (int i = 0; i < s.size(); i++)
		{
			if (i - 2 >= 0) {
				pp_eum = isVowel(s[i - 2]) ? 1 : 0;
			}
			if (i - 1 >= 0) {
				p_eum = isVowel(s[i - 1]) ? 1 : 0;
				p_char = s[i - 1];
			}

			if (!hasVowel && isVowel(s[i])) hasVowel = true;
			if (pp_eum != -1 && p_eum != -1 && pp_eum == p_eum && p_eum == (isVowel(s[i]) ? 1 : 0)) acceptable = false;
			if (s[i] == p_char && s[i] != 'e' && s[i] != 'o') acceptable = false;

		}

		if (!hasVowel) acceptable = false;

		if (acceptable) {
			cout << "<" << s << "> is acceptable." << endl;
		}
		else {
			cout << "<" << s << "> is not acceptable." << endl;
		}

		cin >> s;
	}

}
