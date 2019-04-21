// Codeforces - Serval and Bus - 1153A Div2
#include <bits/stdc++.h>
using namespace std;

const int T = 200100;
int time_bus[T];

int main() {
    int n, t;

    cin >> n >> t;

    for (int i = 0, s, d; i < n; i++) {
        cin >> s >> d;

        while (s < T) {
            time_bus[s] = i+1;
            s += d;
        }
    }

    while (time_bus[t] == 0) {
        t++;
    }

    cout << time_bus[t] << "\n";

    return 0;
}
