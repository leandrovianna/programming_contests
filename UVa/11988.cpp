// UVA - 11988 - Broken Keyboard (a.k.a. Beiju Text)
#include <bits/stdc++.h>
using namespace std;

int main() {
    string text;

    while (cin >> text) {
        list<char> l;
        auto it = l.begin();

        for (const auto &ch : text) {
            if (ch == '[') {
                it = l.begin();
            } else if (ch == ']') {
                it = l.end();
            } else {
                l.insert(it, ch);
            }
        }

        for (auto it = l.begin(); it != l.end(); it++) {
            cout << *it;
        }
        cout << "\n";
    }
    return 0;
}
