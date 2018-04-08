//Codechef - Workers - April Challenge 18
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    const int N = 1010, inf = 110010010;
    int c[N], t;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int ans1 = inf, ans2 = inf, ans3 = inf;
    for (int i = 0; i < n; i++) {
        cin >> t;
        switch (t) {
            case 1:
                ans1 = min(ans1, c[i]);
                break;
            case 2:
                ans2 = min(ans2, c[i]);
                break;
            case 3:
                ans3 = min(ans3, c[i]);
                break;
        }
    }

    cout << min(ans1 + ans2, ans3) << endl;
    return 0;
}
