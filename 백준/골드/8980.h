#include <iostream>
#include <algorithm>

using namespace std;

int N; // 마을 수
int C; // 트럭의 용량
int M; // 박스 정보의 개수

struct box
{
    int from; // 박스를 보내는 마을 번호
    int to; // 박스를 받는 마을 번호
    int cnt; // 보내는 박스 개수
    int dis;
};

// 트럭 한 대로 배송할 수 있는 최대 박스 수를 한 줄에 출력한다.
int p_8980()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C >> M;

    box box_list[M];
    for (int i = 0; i < M; ++i)
    {
        cin >> box_list[i].from >> box_list[i].to >> box_list[i].cnt;
        box_list[i].dis = box_list[i].to - box_list[i].from;
    }


    sort(box_list, box_list + M, [](const box& a, const box& b) -> bool
    {
        // if (a.dis == b.dis)
        // {
        return a.to < b.to;
        // }
        // return a.dis < b.dis;
    });


    int ret = 0;

    int size_limit[N + 1];
    fill_n(size_limit, N + 1, C);

    for (int i = 0; i < M; ++i)
    {
        const box& b = box_list[i];
        const int min_cnt = min(*min_element(size_limit + b.from, size_limit + b.to), b.cnt);
        if (min_cnt > 0)
        {
            for (int j = b.from; j < b.to; ++j)
            {
                size_limit[j] -= min_cnt;
            }
            ret += min_cnt;
        }
    }


    cout << ret;

    return 0;
}

// 레전드 의견 발견
// 어차피 배송되는 상자의 개수만 묻기 때문에 현재 트럭의 박스를 그대로 가져가나 더 먼저 배송되는 박스로 교체하나 두 경우 모두 배송되는 상자의 개수는 동일합니다.
// 따라서 그냥 그 마을에서 보내는 모든 박스를 다 실어버린 다음 목적지가 가장 가까운 C개의 박스만 남겨두고 나머지는 다 버리면 됩니다.
