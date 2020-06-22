// TAP 2018/2 - Building a Field - B8
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N];
int main() {
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int p1 = 0, p2 = -1;
    int sum2 = 0, cnt = 0;
    while (p2 < n) {
        if (sum2 == sum - sum2) {
            cnt++;
            if (cnt == 3) {
                cout << "Y" << endl;
                return 0;
            }
        }

        if (p1 < n-1 && sum2 > sum - sum2) {
            sum2 -= a[p1];
            p1++;
        } else {
            p2++;
            sum2 += a[p2];
        }
    }

    cout << "N" << endl;
    return 0;
}
