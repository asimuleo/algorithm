//
// Created by 임혁 on 2024. 6. 5..
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <iomanip>

using namespace std;


void p_27389() {

//    cin.tie(0);
//    ios::sync_with_stdio(0);


    int n;
    cin >> n;
    n = n * 100;
    n = n/4;
    cout << n / 100 << '.' << n % 100;

}
