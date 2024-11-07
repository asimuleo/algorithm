//
// Created by SSAFY on 24. 9. 19.
//

#include <iostream>
#include <map>


using namespace std;

int p_26069()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    map<string, bool> dance;
    for (int i = 0; i < N; ++i)
    {
        string a, b;
        cin >> a >> b;
        if (a == "ChongChong" || b == "ChongChong" || dance[a] || dance[b])
        {
            dance[a] = true;
            dance[b] = true;
        }
    }

    int ret = 0;

    for (const auto& it : dance)
    {
        if (it.second)
        {
            ret++;
        }
    }
    cout << ret;
    return 0;
}
