//UVA - Perfection - 382
#include <bits/stdc++.h>
using namespace std;

vector<int> get_divisors(int n) {
    vector<int> divs = {1};
    if (n == 1)
        divs.pop_back();
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (n/i != i)
                divs.push_back(n/i);
        }
    }

    return divs;
}

int main() {
    int n;

    cout << "PERFECTION OUTPUT\n";
    while (cin >> n, n != 0) {
        int sum = 0;
        for (const auto &x : get_divisors(n)) {
            sum += x;
        }

        cout << setw(5) << n << "  ";
        if (sum == n) {
            cout << "PERFECT\n";
        } else if (sum < n) {
            cout << "DEFICIENT\n";
        } else {
            cout << "ABUNDANT\n";
        }
    }
    cout << "END OF OUTPUT\n";

    return 0;
}
