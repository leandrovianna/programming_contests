// URI - Lista Telefônica Econômica - 1211
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;

    while (cin >> n) {
        vector<string> phones;

        for (int i = 0; i < n; i++) {
            cin >> s;
            phones.push_back(s);
        }

        sort(phones.begin(), phones.end());

        int ans = 0;
        for (int i = 1, sz = phones.size(); i < sz; i++) {
            int cnt = 0;
            for (int j = 0, sz = phones[i].size();
                    j < sz; j++) {
                if (phones[i-1][j] == phones[i][j])
                    cnt++;
                else
                    break;
            }

            ans += cnt;
        }

        cout << ans << "\n";
    }

    return 0;
}
