// Codeforces - Cram Time - 1072C Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a + b == 0) {
        cout << "0\n0\n";
        return 0;
    }

    int64_t i = 0;
    while ((i * (i+1)) / 2 <= a + b) {
        i++;
    }
    i--;

    vector<int> s1, s2;
    while (i > 0) {
        if (a >= i) {
            s1.push_back(i);
            a -= i;
        } else {
            s2.push_back(i);
        }
        i--;
    }

    cout << s1.size() << "\n";
    for (const auto &x : s1) {
        cout << x << " ";
    }
    cout << "\n" << s2.size() << "\n";
    for (const auto &x : s2) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
