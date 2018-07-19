// UVA - Fill the Containers - 11413
#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

int check(int cap[], const int n, const int maxcap) {
    int acc = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (cap[i] > maxcap) return INF;

        if (acc + cap[i] <= maxcap) {
            acc += cap[i];
        } else {
            count++;
            acc = cap[i];
        }
    }

    count++; // acc > 0, count one more conteiner

    return count;
}

int main() {
    const int N = 1010;
    int n, m;
    int cap[N];

    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> cap[i];
        }

        int lo = 1;
        int hi = INF; // 10**9
        int mid, ans = hi;

        while (lo <= hi) {
            mid = (lo + hi) / 2;

            int ctn = check(cap, n, mid);
//            cout << "with maxcap = " << mid << " were used "
//                << ctn << " conteiners." << endl;

            if (ctn <= m) {
                hi = mid-1;

                assert(mid < ans);
                ans = mid;
            } else {
                lo = mid+1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
