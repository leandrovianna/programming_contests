// Codeforces - Like "A" - 1146A - Forethought Future Cup - Elimination Round
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    for (const auto &ch : s) {
        if (ch == 'a')
            cnt++;
    }

    int n = s.size();

    while (cnt <= n / 2) {
        n--;
    }

    cout << n << "\n";
    return 0;
}
