//
// Created by 임혁 on 24. 8. 07.
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

int K;
int tree[1024];

int p_9934() {

    cin >> K;

    int size = (int) pow(2, K);

    for (int i = 1; i < size; ++i) {
        cin >> tree[i];
    }

    for (int height = K; height >= 1; --height) {
        for (int i = pow(2, height - 1); i < size; i = i + pow(2, height)) {
            cout << tree[i] << ' ';
        }
        cout << '\n';
    }

}