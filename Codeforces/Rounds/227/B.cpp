//Codeforces - Effective Approach - 227B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 100100;
    int n, m, x;
    int first[N], last[N];

    memset(first, -1, sizeof(first));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (first[x] == -1)
            first[x] = i+1;

        last[x] = n - i;
    }

    cin >> m;
    int64_t vasya = 0, petya = 0;
    for (int i = 0; i < m; i++) {
        cin >> x;
        vasya += first[x];
        petya += last[x];
    }

    cout << vasya << " " << petya << endl;
    return 0;
}
