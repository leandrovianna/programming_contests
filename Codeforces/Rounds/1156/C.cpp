// Codeforces - Match Points - 1156C Edu Round
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, z;

    cin >> n >> z;

    multiset<int> ss;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[i] = x;
    }

    sort(a, a+n);
    for (int i = n/2; i < n; i++) {
        ss.insert(a[i]);
    }
    
    int answer = 0;

    for (int i = 0; i < n/2; i++) {
        int b = a[i];

        auto it = ss.lower_bound(b + z);

        if (it != ss.end()) {
            ss.erase(it);
            answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}
