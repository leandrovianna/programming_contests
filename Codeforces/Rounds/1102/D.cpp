// Codeforces - Balanced Ternary String - 1102D Div3
#include <bits/stdc++.h>
using namespace std;

const int N = 300100;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char ch;
    int n;
    int oc[3] = {0, 0, 0};

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        a[i] = ch - '0';
        oc[a[i]]++;
    }

    int p1 = 0;
    while (oc[0] < n / 3) {
        while (p1 < n && oc[a[p1]] <= n / 3) {
            p1++;
        }

        oc[a[p1]]--;
        oc[0]++;
        a[p1] = 0;
        p1++;
    }

    p1 = n-1;
    while (oc[2] < n / 3) {
        while (p1 >= 0 && oc[a[p1]] <= n / 3) {
            p1--;
        }

        oc[a[p1]]--;
        oc[2]++;
        a[p1] = 2;
        p1--;
    }

    while (oc[1] < n / 3) {
        p1 = 0;
        while (oc[2] > n / 3 && oc[1] < n / 3) {
            while (p1 < n && a[p1] != 2) {
                p1++;
            }

            oc[a[p1]]--;
            oc[1]++;
            a[p1] = 1;
            p1++;
            if (p1 == n)
                break;
        }

        p1 = n-1;
        while (oc[0] > n / 3 && oc[1] < n / 3) {
            while (p1 >= 0 && a[p1] != 0) {
                p1--;
            }

            oc[a[p1]]--;
            oc[1]++;
            a[p1] = 1;
            p1--;
            if (p1 < 0)
                break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << "\n";

    return 0;
}
