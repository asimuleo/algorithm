//
// Created by muleo on 24. 8. 21.
//

#include <iostream>

using namespace std;

int p_2091() {
    int X, A, B, C, D;
    cin >> X >> A >> B >> C >> D;


    if (X <= A) {
        // A 개의 1센트로 다 살 수 있어요!
        cout << X << " 0 0 0";
        return 0;
    }
    // 최대 A개에서 하나씩 빼 가면서 도전!
    for (int cent = A; cent >= 0; --cent) {
        int currentX = X - cent;
        if (currentX < 0) continue;
        if (currentX % 5 == 0 && currentX <= B * 5) {
            // B 개의 5센트로 다 살 수 있어요!
            cout << cent << " " << currentX / 5 << " 0 0";
            return 0;
        }
        for (int nickel = B; nickel >= 0; --nickel) {
            int currentX2 = currentX - nickel * 5;
            if (currentX2 < 0) continue;
            if (currentX2 % 10 == 0 && currentX2 <= C * 10) {
                // C 개의 10센트로 다 살 수 있어요!
                cout << cent << " " << nickel << " " << currentX2 / 10 << " 0";
                return 0;
            }
            for (int dime = C; dime >= 0; --dime) {
                int currentX3 = currentX2 - dime * 10;
                if (currentX3 < 0) continue;
                if (currentX3 % 25 == 0 && currentX3 <= D * 25) {
                    // D 개의 25센트로 다 살 수 있어요!
                    // 여기서 5센트를 하나 더 작게 쓰고 10센트를 3개 더 쓸 수 있는지 확인
                    // 25 센트를 하나 덜 쓰는 대신 10센트를 3개 더 쓰는 전략... 대신5센트를 하나 적게 써서
                    // 위 반복문에 먼저 안걸린다.

                    // 여기서 25센트 1개 대신에 10센트 3개 5센트 하나 덜 쓰는 전략
                    if (nickel != 0 && dime + 3 <= C && currentX3 / 25 >= 1 && D >= 1) {
                        cout << cent << " " << nickel - 1 << " " << dime + 3 << " " << currentX3 / 25 - 1;
                    } else {
                        cout << cent << " " << nickel << " " << dime << " " << currentX3 / 25;
                    }

                    return 0;
                }
            }
        }
    }


    cout << "0 0 0 0";
    return 0;
}
