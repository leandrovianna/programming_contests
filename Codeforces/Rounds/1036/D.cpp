// Codeforces - Vasya and Arrays - 1036D - EduRound
#include <bits/stdc++.h>
using namespace std;

const int N = 3 * 1000 * 100 + 10;
int64_t a[N], b[N];

int main() {
    int n, m;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%ld",&b[i]);
    }

    int p1 = 0, p2 = 0;
    int64_t sum1 = 0, sum2 = 0;
    int ans = 0;

    while (p1 < n || p2 < m) {
        if (p2 == m || sum1 < sum2) {
            sum1 += a[p1];
            p1++;
        } else {
            sum2 += b[p2];
            p2++;
        }

        if (sum1 == sum2) {
            sum1 = 0;
            sum2 = 0;
            ans++;
        }
    }

    if (sum1 != sum2)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}
