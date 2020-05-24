// AtCoder - Falling Sleep
#include <bits/stdc++.h>
using namespace std;

const int N = 55;

struct Song {
    string title;
    int dur;
} song[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> song[i].title >> song[i].dur;
    }

    string x;
    cin >> x;

    int ans = 0;
    bool isSum = false;

    for (int i = 0; i < n; i++) {
        if (isSum) {
            ans += song[i].dur;
        }

        if (song[i].title == x) {
            isSum = true;
        }
    }

    cout << ans << "\n";

    return 0;
}

