#include <iostream>
#include <string>

using namespace std;

int main() {

    string s;
    cin >> s;

    while (!s.empty()) {
        string ss = s.substr(0, 2);
        if (ss == "pi" || ss == "ka") {
            s = s.substr(2);
        } else if (s.substr(0, 3) == "chu") {
            s = s.substr(3);
        } else {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
