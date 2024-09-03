//
// Created by SSAFY on 24. 9. 3.
//

#include <iostream>
#include <set>
#include <queue>
#include <cstring>

using namespace std;


int p_15961() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 접시의 수
    int d; // 초밥의 가짓수
    int k; // 연속해서 먹는 접시의 수
    int c; // 쿠폰 번호
    cin >> N >> d >> k >> c;

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ret = 0;


    set<int> s;
    int klist[d + 1];
    memset(klist, 0, sizeof(klist));
    klist[c] = 1;
    s.insert(c);

    int temp;
    queue<int> q;
    for (int i = 0; i < k; ++i) {
        // 입력 받기
        temp = arr[i];
        s.insert(temp);
        q.push(temp);
        klist[temp]++;
    }

    // 개수 새기
    if (ret < s.size()) {
        ret = s.size();
    }


    for (int i = k; i < N; i++) {
        // 빼기
        int front = q.front();
        if (klist[front] == 1) {
            s.erase(s.find(front));
            klist[front]--;
        } else {
            klist[front]--;
        }
        q.pop();

        // 입력 받기
        temp = arr[i];
        s.insert(temp);
        q.push(temp);
        klist[temp]++;

        // 개수 새기
        if (ret < s.size()) {
            ret = s.size();
        }
    }

    // k - 1 번은 더 해줘야함
    for (int i = 0; i < k - 1; i++) {
        // 빼기
        int front = q.front();
        if (klist[front] == 1) {
            s.erase(s.find(front));
            klist[front]--;
        } else {
            klist[front]--;
        }
        q.pop();

        // 입력 받기
        temp = arr[i];
        s.insert(temp);
        q.push(temp);
        klist[temp]++;

        // 개수 새기
        if (ret < s.size()) {
            ret = s.size();
        }
    }

    cout << ret;

    return 0;
}
