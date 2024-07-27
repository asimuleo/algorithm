//
// Created by 임혁 on 24. 7. 27.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <cstring>

using namespace std;

void p_18301() {

    int n1, n2, n12;
    cin >> n1 >> n2 >> n12;

    cout << floor((n1+1) * (n2 + 1) / (n12 + 1) - 1);

}
