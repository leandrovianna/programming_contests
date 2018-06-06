#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans;
    char ch;
    map<char, int> key;


    ans = 0;
    cin >> n;
    for (int i = 0; i < 2*n-2; i++) {
        cin >> ch;
        if (i & 1) {
            ch = tolower(ch);
            if (key[ch] > 0) {
                key[ch]--;
            } else {
                ans++;
            }
        } else {
            key[ch]++;
        }
    }

    cout << ans << endl;

    return 0;
}
