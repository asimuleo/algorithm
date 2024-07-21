//
// Created by 임혁 on 24. 7. 21.
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

int N;

int life[3];

tuple<int, int, int> attack_tuple[6];
pair<int, int> attack_pair[2];
int attack;


int cache[61][61][61];

int play_pair(int life1, int life2) {

    int ret = 1000000000;

    if (life1 <= 0 && life2 <= 0) {
        return 0;
    }

    for (int i = 0; i < 2; ++i) {
        int a, b;
        tie(a, b) = attack_pair[i];

        ret = min(ret, play_pair(life1 - a, life2 - b) + 1);
    }

    return ret;

}

int play_tuple(int life1, int life2, int life3) {



    if (life1 <= 0 && life2 <= 0 && life3 <= 0) {
        return 0;
    }

    if (life1 <= 0 && life2 <= 0) {
        return ((life3 - 1) / attack) + 1;
    }
    if (life1 <= 0 && life3 <= 0) {
        return ((life2 - 1) / attack) + 1;
    }
    if (life2 <= 0 && life3 <= 0) {
        return ((life1 - 1) / attack) + 1;
    }


    if (life1 <= 0)
        return play_pair(life2, life3);
    if (life2 <= 0)
        return play_pair(life1, life3);
    if (life3 <= 0)
        return play_pair(life1, life2);


    // 캐싱
    int arr[] = {life1, life2, life3};
    sort(arr, arr + 3);

    int &ret = cache[arr[0]][arr[1]][arr[2]];

    if (ret != -1)
        return ret;

    int ret2 = 2000000000;

    for (int i = 0; i < 6; ++i) {
        int a, b, c;
        tie(a, b, c) = attack_tuple[i];

        ret2 = min(ret2, play_tuple(life1 - a, life2 - b, life3 - c) + 1);
    }

    return ret = ret2;

}


void p_12869() {

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> life[i];
    }

    attack_tuple[0] = {9, 3, 1};
    attack_tuple[1] = {9, 1, 3};
    attack_tuple[2] = {3, 9, 1};
    attack_tuple[3] = {3, 1, 9};
    attack_tuple[4] = {1, 9, 3};
    attack_tuple[5] = {1, 3, 9};

    attack_pair[0] = {9, 3};
    attack_pair[1] = {3, 9};

    attack = 9;

    if (N == 3) {
        memset(cache, -1, sizeof(cache));
        cout << play_tuple(life[0], life[1], life[2]);
        return;
    }

    if (N == 2) {
        cout << play_pair(life[0], life[1]);
        return;
    }

    // N == 1
    cout << ((life[0] - 1) / attack) + 1;


}