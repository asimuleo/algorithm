#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;


int main() {

    // 특정 점을 가로냐 세로냐로 나눈다.
    int n, m;
    cin >> n >> m;
    string board[n];
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    int ret = 0;

    // 0은 가로 1은 세로
    for (int i = 0; i < (1 << (n * m)); i++) {
        // 모든 조합

        if(i == 51) {
            cout << "";
        }

        int ret_temp = 0;

        // 가로 보기
        for (int s = 0; s < n; s++) {
            int temp = 0;

            for (int g = 0; g < m; g++) {

                if (!(i & (1 << (s * m + g)))) {
                    temp *= 10;
                    temp += board[s][g] - '0';
                } else {
                    ret_temp += temp;
                    temp = 0;
                }
            }
            ret_temp += temp;
        }


        // 세로 보기
        for (int g = 0; g < m; g++) {
            int temp = 0;

            for (int s = 0; s < n; s++) {

                if ((i & (1 << (s * m + g)))) {
                    temp *= 10;
                    temp += board[s][g] - '0';
                } else {
                    ret_temp += temp;
                    temp = 0;
                }

            }
            ret_temp += temp;
        }

        ret = max(ret, ret_temp);
    }

    cout << ret;


    return 0;
}
