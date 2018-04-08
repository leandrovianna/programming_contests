//Codeforces - Tanya and Postcard - 518B Div2
#include <bits/stdc++.h>
using namespace std;

char inv(char x) {
    return isupper(x) ? tolower(x) : toupper(x);
}

int main() {
    map<char, int> cnt;
    const int N = 200100; //2 * 10^5
    bool vis[N];
    memset(vis, 0, sizeof(vis));
    string s, t;
    int countWow = 0, countWhoops = 0;
    
    cin >> s;
    cin >> t;

    for (const auto &c : t) {
        cnt[c]++;
    }

    for (size_t i = 0; i < s.size(); i++) {
        const char c = s[i];
        if (cnt[c] > 0) {
            vis[i] = true;
            countWow++;
            cnt[c]--;
        }
    }

    for (size_t i = 0; i < s.size(); i++) {
        char c = inv(s[i]);
        if (!vis[i] && cnt[c] > 0) {
            countWhoops++;
            cnt[c]--;
        }
    }

    cout << countWow << " " << countWhoops << endl;

    return 0;
}
