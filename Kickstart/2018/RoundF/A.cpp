// Kickstart 2018 - Round F - A - Common Anagrams
#include <bits/stdc++.h>
using namespace std;

void uni(string &t) {
    sort(t.begin(), t.end());
}

int main() {
    int t, l;
    string a, b;

    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> l >> a >> b;

        set<string> unique_substr;
        string t;

        for (int i = 0; i < l; i++) {
            for (int j = i; j < l; j++) {
                t = b.substr(i, j - i + 1); 
                uni(t);
                unique_substr.insert(t);
            }
        }

        int64_t ans = 0;
        for (int i = 0; i < l; i++) {
            for (int j = i; j < l; j++) {
                t = a.substr(i, j - i + 1);
                uni(t);
                if (unique_substr.count(t) > 0) {
                    ans++;
                }
            }
        }

        cout << "Case #" << ti << ": " << ans << "\n";
    }
    return 0;
}
