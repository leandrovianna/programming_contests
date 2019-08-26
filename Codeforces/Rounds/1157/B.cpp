// Codeforces - Long Number - 1157B
#include <bits/stdc++.h>
using namespace std;

const int D = 10, N = 200100;
int f[D];
int num[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;

    cin >> n;
    char ch;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        num[i] = ch - '0';
    }

    for (int i = 1; i < D; i++) {
        cin >> f[i];
    }

    for (int i = 0; i < n; i++) {
        if (f[num[i]] > num[i]) {
            num[i] = f[num[i]];
            for (int j = i+1; j < n; j++) {
                if (f[num[j]] >= num[j]) {
                    num[j] = f[num[j]];
                } else {
                    break;
                }
            }

            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << num[i];
    }

    cout << "\n";

    return 0;
}
