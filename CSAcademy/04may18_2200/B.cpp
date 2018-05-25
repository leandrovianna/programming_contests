#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
int a[N], quack[N];

int main() {
    int n, t, x;

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }

    for (int j = 1; j < N; j++) {
        if (a[j] == 0)
            continue;

        for (int i = j; i <= t; i += j) {
            quack[i] += a[j];
        }
    }

    int ans = 0, qtd = 0;
    for (int i = 1; i <= t; i++) {
        if (quack[i] > ans) {
            ans = quack[i];
            qtd = 1;
        } else if (quack[i] == ans) {
            qtd++;
        }
    }

    cout << ans << " " << qtd << endl;
    return 0;
}
