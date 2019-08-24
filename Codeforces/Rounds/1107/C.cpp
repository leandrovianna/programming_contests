// Codeforces - Brutality - 1107C
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int a[N];
char b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> seqs;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (b[i] == b[i-1]) {
            cnt++;
        } else {
            seqs.push_back(cnt);
            cnt = 1;
        }
    }
    seqs.push_back(cnt);

    int j = 0;
    int64_t sum = 0;

    for (const auto &sz : seqs) {
        for (int i = j; i < j+sz; i++) {
            sum += a[i];
        }

        if (sz > k) {
            multiset<int> ms;
            for (int i = j; i < j+sz; i++) {
                ms.insert(a[i]);
            }

            int rem = sz - k;
            while (rem > 0) {
                int v = *ms.begin();
                sum -= v;
                ms.erase(ms.begin());
                rem--;
            }
        }

        j += sz;
    }

    cout << sum << "\n";
    return 0;
}
