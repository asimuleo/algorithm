//
// Created by 임혁 on 2024. 5. 28..
//

#include "algorithm"
#include <iostream>
#include <vector>
#include <cmath>



using namespace std;

/**
 * 처음에는 재귀로 풀려고 했는데 생각해보니 입력의 개수와 정답일 때의 개수가 9, 7 로 정해져 있었다.
 * 차라리 모든 입력을 더하고 거기서 100을 뺀 수가 되는 두가지 수를 찾고 해당 수를 제외한 나머지 수를 정렬해서 출력해보자고 생각했다.
 */
void p_2309() {

    int arr[9];
    int sum = 0;

    for (int &i: arr) {
        cin >> i;
        sum += i;
    }

    int match = sum - 100;
    bool keep_go = true;

    for (int i = 0; i < 9; ++i) {
        if (!keep_go) {
            break;
        }
        for (int j = i + 1; j < 9; ++j) {
            if (arr[i] + arr[j] == match) {
                arr[i] = -1;
                arr[j] = -1;
                keep_go = false;
                break;
            }
        }
    }

    sort(arr, arr + 9);

    for (int i = 2; i < 9; ++i) {
        cout << arr[i] << endl;
    }


}