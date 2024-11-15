#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S = 0;
    int full = (1 << 20) - 1;

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s;
        int x;

        if (s == "add") {
            cin >> x;
            S |= 1 << (x - 1);
        } else if (s == "remove") {
            cin >> x;
            S &= (full - (1 << (x - 1)));
        } else if (s == "check") {
            cin >> x;
            if (S & (1 << (x - 1))) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (s == "toggle") {
            cin >> x;
            S ^= (1 << (x - 1));
        } else if (s == "all") {
            S = full;
        } else if (s == "empty") {
            S = 0;
        }

    }


    return 0;
}
