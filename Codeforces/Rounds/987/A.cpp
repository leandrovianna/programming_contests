#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    map<string, string> mp =
    {
        {"purple", "Power"},
        {"green", "Time"},
        {"blue", "Space"},
        {"orange", "Soul"},
        {"red", "Reality"},
        {"yellow", "Mind"}
    };

    string s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp.erase(s);
    }

    cout << mp.size() << "\n";
    for (const auto &x : mp) {
        cout << x.second << "\n";
    }
    return 0;
}
