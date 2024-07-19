//
// Created by cs.javah on 2024. 7. 19.
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

struct piece {
    char top;
    char bottom;
    char left;
    char right;
    char front;
    char back;
};

// 9개의 조각으로 이뤄진 큐브
// 13 인덱스가 정 중앙이다.
// 0 ~ 26
piece cube[27];

void init() {
    // 흰색은 w,
    // 노란색은 y,
    // 빨간색은 r,
    // 오렌지색은 o,
    // 초록색은 g,
    // 파란색은 b,

    // 맨 위 층
    cube[0] = {'w', ' ', 'g', ' ', 'r', ' '};
    cube[1] = {'w', ' ', ' ', ' ', 'r', ' '};
    cube[2] = {'w', ' ', ' ', 'b', 'r', ' '};

    cube[3] = {'w', ' ', 'g', ' ', ' ', ' '};
    cube[4] = {'w', ' ', ' ', ' ', ' ', ' '};
    cube[5] = {'w', ' ', ' ', 'b', ' ', ' '};

    cube[6] = {'w', ' ', 'g', ' ', ' ', 'o'};
    cube[7] = {'w', ' ', ' ', ' ', ' ', 'o'};
    cube[8] = {'w', ' ', ' ', 'b', ' ', 'o'};

    // 중간 층
    cube[9] = {' ', ' ', 'g', ' ', 'r', ' '};
    cube[10] = {' ', ' ', ' ', ' ', 'r', ' '};
    cube[11] = {' ', ' ', ' ', 'b', 'r', ' '};

    cube[12] = {' ', ' ', 'g', ' ', ' ', ' '};
    cube[13] = {' ', ' ', ' ', ' ', ' ', ' '};
    cube[14] = {' ', ' ', ' ', 'b', ' ', ' '};

    cube[15] = {' ', ' ', 'g', ' ', ' ', 'o'};
    cube[16] = {' ', ' ', ' ', ' ', ' ', 'o'};
    cube[17] = {' ', ' ', ' ', 'b', ' ', 'o'};

    // 바닥 층
    cube[18] = {' ', 'y', 'g', ' ', 'r', ' '};
    cube[19] = {' ', 'y', ' ', ' ', 'r', ' '};
    cube[20] = {' ', 'y', ' ', 'b', 'r', ' '};

    cube[21] = {' ', 'y', 'g', ' ', ' ', ' '};
    cube[22] = {' ', 'y', ' ', ' ', ' ', ' '};
    cube[23] = {' ', 'y', ' ', 'b', ' ', ' '};

    cube[24] = {' ', 'y', 'g', ' ', ' ', 'o'};
    cube[25] = {' ', 'y', ' ', ' ', ' ', 'o'};
    cube[26] = {' ', 'y', ' ', 'b', ' ', 'o'};
}

void printCubeUp() {
    cout << cube[6].top;
    cout << cube[7].top;
    cout << cube[8].top << '\n';
    cout << cube[3].top;
    cout << cube[4].top;
    cout << cube[5].top << '\n';
    cout << cube[0].top;
    cout << cube[1].top;
    cout << cube[2].top << endl;
}

void printCubeBack() {
    cout << cube[6].back;
    cout << cube[7].back;
    cout << cube[8].back << '\n';
    cout << cube[15].back;
    cout << cube[16].back;
    cout << cube[17].back << '\n';
    cout << cube[24].back;
    cout << cube[25].back;
    cout << cube[26].back << endl;
}

void printCubeFront() {
    cout << cube[0].front;
    cout << cube[1].front;
    cout << cube[2].front << '\n';
    cout << cube[9].front;
    cout << cube[10].front;
    cout << cube[11].front << '\n';
    cout << cube[18].front;
    cout << cube[19].front;
    cout << cube[20].front << endl;
}

void printCubeDown() {
    cout << cube[24].bottom;
    cout << cube[25].bottom;
    cout << cube[26].bottom << '\n';
    cout << cube[21].bottom;
    cout << cube[22].bottom;
    cout << cube[23].bottom << '\n';
    cout << cube[18].bottom;
    cout << cube[19].bottom;
    cout << cube[20].bottom << endl;
}

void printCubeLeft() {
    cout << cube[6].left;
    cout << cube[3].left;
    cout << cube[0].left << '\n';
    cout << cube[15].left;
    cout << cube[12].left;
    cout << cube[9].left << '\n';
    cout << cube[24].left;
    cout << cube[21].left;
    cout << cube[18].left << endl;
}

void printCubeRight() {
    cout << cube[2].right;
    cout << cube[5].right;
    cout << cube[8].right << '\n';
    cout << cube[11].right;
    cout << cube[14].right;
    cout << cube[17].right << '\n';
    cout << cube[20].right;
    cout << cube[23].right;
    cout << cube[26].right << endl;
}


/**
 *
 */


void front_plus() {
    int t1 = cube[18].left;
    int t2 = cube[18].front;
    int t3 = cube[18].bottom;
    int t4 = cube[9].left;
    int t5 = cube[9].front;
    int t6 = cube[0].left;
    int t7 = cube[0].front;
    int t8 = cube[0].top;
    int t9 = cube[19].bottom;
    int t10 = cube[19].front;
    int t11 = cube[1].top;
    int t12 = cube[1].front;
    int t13 = cube[20].right;
    int t14 = cube[20].bottom;
    int t15 = cube[20].front;
    int t16 = cube[11].right;
    int t17 = cube[11].front;
    int t18 = cube[2].right;
    int t19 = cube[2].top;
    int t20 = cube[2].front;


    cube[0].top = t1;
    cube[0].front = t2;
    cube[0].left = t3;

    cube[1].top = t4;
    cube[1].front = t5;

    cube[2].top = t6;
    cube[2].front = t7;
    cube[2].right = t8;

    cube[9].left = t9;
    cube[9].front = t10;

    // cube[10]

    cube[11].right = t11;
    cube[11].front = t12;

    cube[18].bottom = t13;
    cube[18].left = t14;
    cube[18].front = t15;

    cube[19].bottom = t16;
    cube[19].front = t17;

    cube[20].bottom = t18;
    cube[20].right = t19;
    cube[20].front = t20;
}

void front_minus() {
    int t1 = cube[2].right;
    int t2 = cube[2].front;
    int t3 = cube[2].top;
    int t4 = cube[11].right;
    int t5 = cube[11].front;
    int t6 = cube[20].right;
    int t7 = cube[20].front;
    int t8 = cube[20].bottom;
    int t9 = cube[1].top;
    int t10 = cube[1].front;
    int t11 = cube[19].bottom;
    int t12 = cube[19].front;
    int t13 = cube[0].left;
    int t14 = cube[0].top;
    int t15 = cube[0].front;
    int t16 = cube[9].left;
    int t17 = cube[9].front;
    int t18 = cube[18].left;
    int t19 = cube[18].bottom;
    int t20 = cube[18].front;


    cube[0].top = t1;
    cube[0].front = t2;
    cube[0].left = t3;

    cube[1].top = t4;
    cube[1].front = t5;

    cube[2].top = t6;
    cube[2].front = t7;
    cube[2].right = t8;

    cube[9].left = t9;
    cube[9].front = t10;

    // cube[10]

    cube[11].right = t11;
    cube[11].front = t12;

    cube[18].bottom = t13;
    cube[18].left = t14;
    cube[18].front = t15;

    cube[19].bottom = t16;
    cube[19].front = t17;

    cube[20].bottom = t18;
    cube[20].right = t19;
    cube[20].front = t20;
}

void back_minus() {
    int t1 = cube[24].left;
    int t2 = cube[24].back;
    int t3 = cube[24].bottom;
    int t4 = cube[15].left;
    int t5 = cube[15].back;
    int t6 = cube[6].left;
    int t7 = cube[6].back;
    int t8 = cube[6].top;
    int t9 = cube[25].bottom;
    int t10 = cube[25].back;
    int t11 = cube[7].top;
    int t12 = cube[7].back;
    int t13 = cube[26].right;
    int t14 = cube[26].bottom;
    int t15 = cube[26].back;
    int t16 = cube[17].right;
    int t17 = cube[17].back;
    int t18 = cube[8].right;
    int t19 = cube[8].top;
    int t20 = cube[8].back;


    cube[6].top = t1;
    cube[6].back = t2;
    cube[6].left = t3;

    cube[7].top = t4;
    cube[7].back = t5;

    cube[8].top = t6;
    cube[8].back = t7;
    cube[8].right = t8;

    cube[15].left = t9;
    cube[15].back = t10;

    // cube[16]

    cube[17].right = t11;
    cube[17].back = t12;

    cube[24].bottom = t13;
    cube[24].left = t14;
    cube[24].back = t15;

    cube[25].bottom = t16;
    cube[25].back = t17;

    cube[26].bottom = t18;
    cube[26].right = t19;
    cube[26].back = t20;
}

void back_plus() {
    int t1 = cube[8].right;
    int t2 = cube[8].back;
    int t3 = cube[8].top;
    int t4 = cube[17].right;
    int t5 = cube[17].back;
    int t6 = cube[26].right;
    int t7 = cube[26].back;
    int t8 = cube[26].bottom;
    int t9 = cube[7].top;
    int t10 = cube[7].back;
    int t11 = cube[25].bottom;
    int t12 = cube[25].back;
    int t13 = cube[6].left;
    int t14 = cube[6].top;
    int t15 = cube[6].back;
    int t16 = cube[15].left;
    int t17 = cube[15].back;
    int t18 = cube[24].left;
    int t19 = cube[24].bottom;
    int t20 = cube[24].back;


    cube[6].top = t1;
    cube[6].back = t2;
    cube[6].left = t3;

    cube[7].top = t4;
    cube[7].back = t5;

    cube[8].top = t6;
    cube[8].back = t7;
    cube[8].right = t8;

    cube[15].left = t9;
    cube[15].back = t10;

    // cube[16]

    cube[17].right = t11;
    cube[17].back = t12;

    cube[24].bottom = t13;
    cube[24].left = t14;
    cube[24].back = t15;

    cube[25].bottom = t16;
    cube[25].back = t17;

    cube[26].bottom = t18;
    cube[26].right = t19;
    cube[26].back = t20;
}

void up_plus() {
    int t1 = cube[0].front;
    int t2 = cube[0].top;
    int t3 = cube[0].left;
    int t4 = cube[3].left;
    int t5 = cube[3].top;
    int t6 = cube[6].left;
    int t7 = cube[6].top;
    int t8 = cube[6].back;
    int t9 = cube[1].front;
    int t10 = cube[1].top;

    int t11 = cube[7].back;
    int t12 = cube[7].top;
    int t13 = cube[2].front;
    int t14 = cube[2].right;
    int t15 = cube[2].top;
    int t16 = cube[5].right;
    int t17 = cube[5].top;
    int t18 = cube[8].right;
    int t19 = cube[8].back;
    int t20 = cube[8].top;


    cube[6].left = t1;
    cube[6].top = t2;
    cube[6].back = t3;

    cube[7].back = t4;
    cube[7].top = t5;

    cube[8].back = t6;
    cube[8].top = t7;
    cube[8].right = t8;

    cube[3].left = t9;
    cube[3].top = t10;

    // cube[4]

    cube[5].right = t11;
    cube[5].top = t12;

    cube[0].left = t13;
    cube[0].front = t14;
    cube[0].top = t15;

    cube[1].front = t16;
    cube[1].top = t17;

    cube[2].front = t18;
    cube[2].right = t19;
    cube[2].top = t20;
}

void up_minus() {
    int t1 = cube[8].back;
    int t2 = cube[8].top;
    int t3 = cube[8].right;
    int t4 = cube[5].right;
    int t5 = cube[5].top;
    int t6 = cube[2].right;
    int t7 = cube[2].top;
    int t8 = cube[2].front;
    int t9 = cube[7].back;
    int t10 = cube[7].top;

    int t11 = cube[1].front;
    int t12 = cube[1].top;
    int t13 = cube[6].back;
    int t14 = cube[6].left;
    int t15 = cube[6].top;
    int t16 = cube[3].left;
    int t17 = cube[3].top;
    int t18 = cube[0].left;
    int t19 = cube[0].front;
    int t20 = cube[0].top;


    cube[6].left = t1;
    cube[6].top = t2;
    cube[6].back = t3;

    cube[7].back = t4;
    cube[7].top = t5;

    cube[8].back = t6;
    cube[8].top = t7;
    cube[8].right = t8;

    cube[3].left = t9;
    cube[3].top = t10;

    // cube[4]

    cube[5].right = t11;
    cube[5].top = t12;

    cube[0].left = t13;
    cube[0].front = t14;
    cube[0].top = t15;

    cube[1].front = t16;
    cube[1].top = t17;

    cube[2].front = t18;
    cube[2].right = t19;
    cube[2].top = t20;
}

void down_minus() {
    int t1 = cube[18].front;
    int t2 = cube[18].bottom;
    int t3 = cube[18].left;
    int t4 = cube[21].left;
    int t5 = cube[21].bottom;
    int t6 = cube[24].left;
    int t7 = cube[24].bottom;
    int t8 = cube[24].back;
    int t9 = cube[19].front;
    int t10 = cube[19].bottom;

    int t11 = cube[25].back;
    int t12 = cube[25].bottom;
    int t13 = cube[20].front;
    int t14 = cube[20].right;
    int t15 = cube[20].bottom;
    int t16 = cube[23].right;
    int t17 = cube[23].bottom;
    int t18 = cube[26].right;
    int t19 = cube[26].back;
    int t20 = cube[26].bottom;


    cube[24].left = t1;
    cube[24].bottom = t2;
    cube[24].back = t3;

    cube[25].back = t4;
    cube[25].bottom = t5;

    cube[26].back = t6;
    cube[26].bottom = t7;
    cube[26].right = t8;

    cube[21].left = t9;
    cube[21].bottom = t10;

    // cube[4]

    cube[23].right = t11;
    cube[23].bottom = t12;

    cube[18].left = t13;
    cube[18].front = t14;
    cube[18].bottom = t15;

    cube[19].front = t16;
    cube[19].bottom = t17;

    cube[20].front = t18;
    cube[20].right = t19;
    cube[20].bottom = t20;
}

void down_plus() {
    int t1 = cube[26].back;
    int t2 = cube[26].bottom;
    int t3 = cube[26].right;
    int t4 = cube[23].right;
    int t5 = cube[23].bottom;
    int t6 = cube[20].right;
    int t7 = cube[20].bottom;
    int t8 = cube[20].front;
    int t9 = cube[25].back;
    int t10 = cube[25].bottom;

    int t11 = cube[19].front;
    int t12 = cube[19].bottom;
    int t13 = cube[24].back;
    int t14 = cube[24].left;
    int t15 = cube[24].bottom;
    int t16 = cube[21].left;
    int t17 = cube[21].bottom;
    int t18 = cube[18].left;
    int t19 = cube[18].front;
    int t20 = cube[18].bottom;


    cube[24].left = t1;
    cube[24].bottom = t2;
    cube[24].back = t3;

    cube[25].back = t4;
    cube[25].bottom = t5;

    cube[26].back = t6;
    cube[26].bottom = t7;
    cube[26].right = t8;

    cube[21].left = t9;
    cube[21].bottom = t10;

    // cube[4]

    cube[23].right = t11;
    cube[23].bottom = t12;

    cube[18].left = t13;
    cube[18].front = t14;
    cube[18].bottom = t15;

    cube[19].front = t16;
    cube[19].bottom = t17;

    cube[20].front = t18;
    cube[20].right = t19;
    cube[20].bottom = t20;
}

void left_plus() {
    int t1 = cube[24].left;
    int t2 = cube[24].bottom;
    int t3 = cube[24].back;

    int t4 = cube[15].left;
    int t5 = cube[15].back;

    int t6 = cube[6].left;
    int t7 = cube[6].back;
    int t8 = cube[6].top;

    int t9 = cube[21].left;
    int t10 = cube[21].bottom;

    int t11 = cube[3].left;
    int t12 = cube[3].top;

    int t13 = cube[18].left;
    int t14 = cube[18].bottom;
    int t15 = cube[18].front;

    int t16 = cube[9].left;
    int t17 = cube[9].front;

    int t18 = cube[0].left;
    int t19 = cube[0].top;
    int t20 = cube[0].front;


    cube[6].left = t1;
    cube[6].back = t2;
    cube[6].top = t3;

    cube[3].left = t4;
    cube[3].top = t5;

    cube[0].left = t6;
    cube[0].top = t7;
    cube[0].front = t8;

    cube[15].left = t9;
    cube[15].back = t10;

    // cube[12]

    cube[9].left = t11;
    cube[9].front = t12;

    cube[24].left = t13;
    cube[24].back = t14;
    cube[24].bottom = t15;

    cube[21].left = t16;
    cube[21].bottom = t17;

    cube[18].left = t18;
    cube[18].front = t19;
    cube[18].bottom = t20;
}

void left_minus() {
    int t1 = cube[0].left;
    int t2 = cube[0].top;
    int t3 = cube[0].front;

    int t4 = cube[9].left;
    int t5 = cube[9].front;

    int t6 = cube[18].left;
    int t7 = cube[18].front;
    int t8 = cube[18].bottom;

    int t9 = cube[3].left;
    int t10 = cube[3].top;

    int t11 = cube[21].left;
    int t12 = cube[21].bottom;

    int t13 = cube[6].left;
    int t14 = cube[6].top;
    int t15 = cube[6].back;

    int t16 = cube[15].left;
    int t17 = cube[15].back;

    int t18 = cube[24].left;
    int t19 = cube[24].bottom;
    int t20 = cube[24].back;


    cube[6].left = t1;
    cube[6].back = t2;
    cube[6].top = t3;

    cube[3].left = t4;
    cube[3].top = t5;

    cube[0].left = t6;
    cube[0].top = t7;
    cube[0].front = t8;

    cube[15].left = t9;
    cube[15].back = t10;

    // cube[12]

    cube[9].left = t11;
    cube[9].front = t12;

    cube[24].left = t13;
    cube[24].back = t14;
    cube[24].bottom = t15;

    cube[21].left = t16;
    cube[21].bottom = t17;

    cube[18].left = t18;
    cube[18].front = t19;
    cube[18].bottom = t20;
}

void right_plus() {
    int t1 = cube[20].right;
    int t2 = cube[20].bottom;
    int t3 = cube[20].front;

    int t4 = cube[11].right;
    int t5 = cube[11].front;

    int t6 = cube[2].right;
    int t7 = cube[2].front;
    int t8 = cube[2].top;

    int t9 = cube[23].right;
    int t10 = cube[23].bottom;

    int t11 = cube[5].right;
    int t12 = cube[5].top;

    int t13 = cube[26].right;
    int t14 = cube[26].bottom;
    int t15 = cube[26].back;

    int t16 = cube[17].right;
    int t17 = cube[17].back;

    int t18 = cube[8].right;
    int t19 = cube[8].top;
    int t20 = cube[8].back;


    cube[2].right = t1;
    cube[2].front = t2;
    cube[2].top = t3;

    cube[5].right = t4;
    cube[5].top = t5;

    cube[8].right = t6;
    cube[8].top = t7;
    cube[8].back = t8;

    cube[11].right = t9;
    cube[11].front = t10;

    // cube[14]

    cube[17].right = t11;
    cube[17].back = t12;

    cube[20].right = t13;
    cube[20].front = t14;
    cube[20].bottom = t15;

    cube[23].right = t16;
    cube[23].bottom = t17;

    cube[26].right = t18;
    cube[26].back = t19;
    cube[26].bottom = t20;
}

void right_minus() {
    int t1 = cube[8].right;
    int t2 = cube[8].top;
    int t3 = cube[8].back;

    int t4 = cube[17].right;
    int t5 = cube[17].back;

    int t6 = cube[26].right;
    int t7 = cube[26].back;
    int t8 = cube[26].bottom;

    int t9 = cube[5].right;
    int t10 = cube[5].top;

    int t11 = cube[23].right;
    int t12 = cube[23].bottom;

    int t13 = cube[2].right;
    int t14 = cube[2].top;
    int t15 = cube[2].front;

    int t16 = cube[11].right;
    int t17 = cube[11].front;

    int t18 = cube[20].right;
    int t19 = cube[20].bottom;
    int t20 = cube[20].front;


    cube[2].right = t1;
    cube[2].front = t2;
    cube[2].top = t3;

    cube[5].right = t4;
    cube[5].top = t5;

    cube[8].right = t6;
    cube[8].top = t7;
    cube[8].back = t8;

    cube[11].right = t9;
    cube[11].front = t10;

    // cube[14]

    cube[17].right = t11;
    cube[17].back = t12;

    cube[20].right = t13;
    cube[20].front = t14;
    cube[20].bottom = t15;

    cube[23].right = t16;
    cube[23].bottom = t17;

    cube[26].right = t18;
    cube[26].back = t19;
    cube[26].bottom = t20;
}


void p_5373() {
    int T;
    cin >> T;

    for (int test_case = 0; test_case < T; ++test_case) {
        // 큐브 초기화
        init();


        // 큐브 돌린 횟수
        int n;
        cin >> n;

        // 돌리기
        for (int i = 0; i < n; ++i) {
            char command;
            char rotation;
            cin >> command >> rotation;

            switch (command) {
                case 'L':
                    rotation == '+' ? left_plus() : left_minus();
                    break;
                case 'R':
                    rotation == '+' ? right_plus() : right_minus();
                    break;
                case 'U':
                    rotation == '+' ? up_plus() : up_minus();
                    break;
                case 'D':
                    rotation == '+' ? down_plus() : down_minus();
                    break;
                case 'F':
                    rotation == '+' ? front_plus() : front_minus();
                    break;
                case 'B':
                    rotation == '+' ? back_plus() : back_minus();
                    break;
            }
            // cout << endl;
            // printCubeUp();
            // cout << endl;
            // printCubeDown();
            // cout << endl;
            // printCubeLeft();
            // cout << endl;
            // printCubeRight();
            // cout << endl;
            // printCubeFront();
            // cout << endl;
            // printCubeBack();
            // cout << endl;
        }

        printCubeUp();
    }
}
