//
// Created by SSAFY on 24. 9. 11.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct absum
{
    int a;
    int b;
    int sum;
};

int p_20366()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    vector<absum> list;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            list.push_back(absum{i, j, arr[i] + arr[j]});
        }
    }
    sort(list.begin(), list.end(), [](absum a, absum b) -> bool { return a.sum < b.sum; });

    int ret = INT_MAX;
    for (int i = 0; i < list.size() - 1; ++i)
    {
        int step = 1;
        absum l = list[i];
        absum r = list[i + step];
        while (l.a == r.a || l.a == r.b || l.b == r.a || l.b == r.b)
        {
            step++;
            r = list[i + step];
            if (i + step == list.size()) break;
        }
        if (i + step == list.size()) continue;
        ret = min(ret, r.sum - l.sum);
    }

    cout << ret;
    return 0;
}
