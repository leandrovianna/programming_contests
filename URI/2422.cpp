// URI - Soma das Casas
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N];

int main() {
    int n, k;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> k;

    for (int i = 0; i < n; i++) {
        int ini = i+1, fim = n-1;
        int mid;

        while (ini <= fim) {
            mid = (ini + fim) / 2;

            if (a[mid] + a[i] == k) {
                cout << a[i] << " " << a[mid] << "\n";
                return 0;
            } else if (a[mid] + a[i] < k) {
                ini = mid+1;
            } else {
                fim = mid-1;
            }
        }
    }
    return 0;
}
