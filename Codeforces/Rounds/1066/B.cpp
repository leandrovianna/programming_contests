// Codeforces - Heaters - 1066B Div3
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 1010;
    int n, r, a[N];

    cin >> n >> r;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int last = -1;
    int ans = 0;
    while (last < n-1) {
        int pos = -1;
        for (int i = min(n - 1, last + r); 
                i > max(-1, last - r + 1); --i) {
            if (a[i] == 1) {
				pos = i;
				break;
			}
		}

        if (pos == -1) {
            cout << "-1\n";
            return 0;
        }

        last = pos + r - 1;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
