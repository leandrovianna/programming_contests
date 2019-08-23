// Codeforces - 1204A - BowWow and the Timetable
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    cin >> s;

    if (s == "0") {
        cout << "0\n";
    } else {
        int idx = s.size() - 1;
        int qtd = count(s.begin(), s.end(), '1');
        if (qtd > 1 && idx % 2 == 0) {
            cout << (idx+1) / 2 + 1 << "\n";
        } else {
            cout << (idx+1) / 2 << "\n";
        }
    }

    return 0;
}
