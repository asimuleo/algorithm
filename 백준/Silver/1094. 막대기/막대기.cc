#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;


int main() {
    int x;
    cin >> x;

    // 몇 개의 막대를 풀로 붙여서 Xcm를 만들 수 있는지 출력한다.

    int start = 64;

    deque<int> sticks;
    sticks.push_back(start);


    // 합이 X보다 크다면, 아래와 같은 과정을 반복
    while (reduce(sticks.begin(), sticks.end()) > x) {
        // 1 가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자른다.
        sort(sticks.begin(), sticks.end());
        int f = sticks.front();
        sticks.pop_front();


        int f2 = f / 2;
        sticks.push_front(f2);
        if (reduce(sticks.begin(), sticks.end()) < x) {
            sticks.push_front(f2);
        }
    }

    cout << sticks.size();


    return 0;
}
