#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int fst[N];

int calc(int a[], int n) {
    int ans, maxdist = 0;
    memset(fst, -1, sizeof(fst));
    for (int i = 0; i < 2*n; i++) {
        cout << a[i] << " ";
        if (fst[a[i]] == -1) {
            fst[a[i]] = i;
        } else {
            if (maxdist <= i - fst[a[i]]) {
                maxdist = i - fst[a[i]];
                ans = a[i];
            }
        }
    }
    cout << endl;

    return (maxdist == 1 ? -1 : ans);
}

int main() {
    int n;
    int a[N];

    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];
    }

    int j;
    int ans = 0;
    while ((j = calc(a, n)) != -1) { cout << "found j: " << j << endl;
        bool swapmode = false;

        int pos1 = -1, pos2 = -1;
        for (int i = 0; i < 2*n; i++) {
            if (a[i] == j) {
                if (pos1 == -1)
                    pos1 = i;
                else {
                    pos2 = i;
                    break;
                }
            }
        }

        cout << "pos1: " << pos1 << " "
            << "pos2: " << pos2 << endl;

        if (1 + pos1 <= 2*n - pos2) {
            for (int i = pos2; i > pos1; i--) {
                ans++;
                swap(a[i], a[i-1]);
            }
        } else {
            for (int i = pos1; i < pos2; i++) {
                ans++;
                swap(a[i], a[i+1]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
