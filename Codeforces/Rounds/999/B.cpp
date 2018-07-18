// Codeforces - Reversing Encryption - 999B Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    
    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            for (int j = 0; j < i/2; j++) {
                swap(s[j], s[i-1-j]);
            }
        }
    }

    cout << s << endl;
    return 0;
}
