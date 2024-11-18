#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    string c;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    bool plus = false;

    int i;

    for (i = 0; i < a.size() || i < b.size(); i++) {
        int temp;
        if (i >= a.size()) {
            temp = (b[i] - '0');
        } else if (i >= b.size()) {
            temp = (a[i] - '0');
        } else {
            temp = (a[i] - '0') + (b[i] - '0');
        }
        if (plus) {
            temp++;
        }
        plus = false;
        if (temp >= 10) {
            plus = true;
        }

        c.push_back(char('0' + (temp % 10)));
    }

    if (plus) {
        c.push_back('1');
    }

    reverse(c.begin(), c.end());

    cout << c;

    return 0;
}
