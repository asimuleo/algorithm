//
// Created by 임혁 on 24. 8. 25.
//

#include "iostream"

using namespace std;

int N;
int price[200][200];
bool visited[200][200];

int ret = 2000000000;

void play(int start, int size, int sum) {
    if (sum >= ret) return;
    if (size == 3) {
        ret = sum;
        return;
    }
    for (int i = start / N; i < N; ++i) {
        for (int j = start % N; j < N; ++j,++start) {
            if (i <= 0 || i >= N - 1 || j <= 0 || j >= N - 1) continue;
            if (visited[i - 1][j]) continue;
            if (visited[i][j + 1]) continue;
            if (visited[i + 1][j]) continue;
            if (visited[i][j - 1]) continue;
            if (visited[i][j]) continue;
            visited[i - 1][j] = true;
            visited[i][j + 1] = true;
            visited[i + 1][j] = true;
            visited[i][j - 1] = true;
            visited[i][j] = true;
            play(start + 1, size + 1, sum + price[i - 1][j]
                                                      + price[i][j + 1]
                                                      + price[i + 1][j]
                                                      + price[i][j - 1]
                                                      + price[i][j]);
            visited[i - 1][j] = false;
            visited[i][j + 1] = false;
            visited[i + 1][j] = false;
            visited[i][j - 1] = false;
            visited[i][j] = false;
        }
    }

}

int p_14620() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> price[i][j];
        }
    }
    play(0, 0, 0);
    cout << ret;
}