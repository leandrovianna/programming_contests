#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
bool notprime[N];

int main() {
    int a, b, c, d;
    int64_t count1 = 0, count2 = 0;

    cin >> a >> b >> c >> d;

    for (int i = a; i <= b; i++) {

    }

    for (int i = 2; i <= b; i++) {
        if (notprime[i] == false) {
            for (int j = i + i; j <= b; j += i) {
                if (j >= a && notprime[j] == false)
                    count1++;
                notprime[j] = true;
            }
        }
    }

    memset(notprime, 0, sizeof(notprime));

    for (int i = 2; i <= d; i++) {
        if (notprime[i] == false) {
            for (int j = i + i; j <= d; j += i) {
                if (j >= c && notprime[j] == false)
                    count2++;
                notprime[j] = true;
            }
        }
    }

    int64_t ans = count1 * count2, total = (b-a+1) * (d-c+1);
    if (a == 1)
        ans += d - c + 1;
    if (c == 1)
        ans += b - a + 1;

    cout << total - ans << endl;

    return 0;
}
