#include <iostream>
#include <algorithm>

using namespace std;

int N; // N 종류의 당근
int T; // T 일 동안

struct carrot
{
    long long w; // 초기 맛
    long long p; // 증가하는 맛
};

int p_18234()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T;

    carrot c[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> c[i].w >> c[i].p;
    }

    long long ret = 0;

    // 맨 끝 N - 1 일은 확정
    sort(c, c + N, [](const carrot& a, const carrot& b) -> bool { return a.p < b.p; });

    for (int i = 1; i < N; ++i)
    {
        ret += c[i].w + c[i].p * (i + T - (N - 1) - 1);
    }

    // 앞 T - (N - 1) 일은 조건 비교

    ret += max(
        c[0].w * (T - (N - 1)),
        c[0].w + c[0].p * (T - (N - 1) - 1)
    );

    cout << ret;

    return 0;
}
