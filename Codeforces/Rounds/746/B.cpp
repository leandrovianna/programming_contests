//Codeforces - Decoding - 746B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    string s;
    string t;

    cin >> n >> s;

    t = s;
    int p1, p2;

    if (n % 2 == 0) {
        p1 = n/2 - 1;
        p2 = p1 + 1;
    } else {
        p1 = n/2;
        p2 = p1 - 1;
    }

    bool flag = true;

    for (int i = 0; i < n; i++) {
        if (flag) {
            t[p1] = s[i];
            if (n % 2 == 0)
                p1--;
            else
                p1++;
        } else {
            t[p2] = s[i];
            if (n % 2 == 0)
                p2++;
            else
                p2--;
        }

        flag = !flag;
    }

    cout << t << endl;
    return 0;
}
