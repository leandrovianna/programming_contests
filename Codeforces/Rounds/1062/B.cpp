#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
bool is_square(int64_t x) {
    return (fabs(sqrt(x) - floor(sqrt(x))) < eps);
}

const int M = 1010;
int fac[M];

int main() {
    int64_t n;
    cin >> n;
    int64_t ans = 0, l_ans = 0, min_num = n;

    if (n == 1) {
        cout << "1 0\n";
        return 0;
    }

    int64_t m = 0, x = 0;

    for (int ti = 0; ti < 10; ti++) {
        while (is_square(n)) {
            n = sqrt(n);
            cout << "sqrt -> " << n << endl;
            l_ans++;
        }

        if (n < min_num) {
            ans = l_ans;
            min_num = n;
        }

        // tenta chegar em um quadrado perfeito usando mult
        x = n;
        m = n;
        int e = 0;
        for (int64_t i = 2; i * i <= m; i++) {
            fac[i] = 0;
            while (m % i == 0) {
                fac[i]++;
                m /= i;
            }

            e = max(e, fac[i]);
        }

        if (e & 1)
            e++;

        if (m > 1) {
            for (int j = 1; j < e; j++) {
                n *= m;
            }
        }

        for (int64_t i = 2; i < M; i++) {
            if (fac[i] == 0)
                continue;
            for (int j = fac[i]; j < e; j++) {
                n *= i;
            }
        }

        // se conseguiu aumentar o n
        if (x != n) {
            l_ans++; // mult operation
            cout << "mult -> " << n << endl;
        }

        // sqrt operation
        while (is_square(n)) {
            n = sqrt(n);
            cout << "sqrt -> " << n << endl;
            l_ans++;
        }

        if (n < min_num) {
            ans = l_ans;
            min_num = n;
        }
    }

    cout << min_num << " " << ans << endl;
    return 0;
}
