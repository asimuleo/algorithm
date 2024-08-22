//
// Created by 임혁 on 24. 8. 3.
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


vector<int> list;
vector<char> list_c;

void p_18867() {


    char c = '!';
    long long dap = 0;

    for (int i = 0; i < 94; ++i) {

        long long tmp = 1;
        for (int j = 0; j < 814; j++) {
            tmp = (tmp * c) % 20200429;
        }


        list.push_back(tmp);
        list_c.push_back(c);
        c++;

    }

    for (int a = 0; a < list.size(); ++a) {
        for (int i = 0; i < 990316; ++i) {
            long long sum = 0;
            for (int j = 0; j <= i; ++j) {
                sum += list[a];
                if (sum % 20200429 == 20200402) {
                    cout << "";
                }
            }

        }
    }




    for (int k = 0; k < list.size(); ++k) {
        long long r = list[k];
        long long cnt = 1;
        while (true) {

            for (int i = 0; i < list.size(); ++i) {
                if ((r + list[i] * 6) % 20200429 == 20200402) {
                    return;
                }
            }

            r = r + r;
            if (r < 0) {
                break;
            }
            cnt++;
        }
    }



//    cout << "";


//     list[1] (!) 를 17582 번 출력하고  list[50] (S) 를 1번 출력
//     list[55]

//    for (int i = 0; i < 17582; ++i) {
//        cout << '!';
//    }
//    cout << 'S';

}