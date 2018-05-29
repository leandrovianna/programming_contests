// Codeforces - Fox Dividing Cheese - 371B Div2
#include <bits/stdc++.h>
using namespace std;

void get_primes(int n, map<int, int> &cnt) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cnt[i]++;
            n /= i;
        }
    }

    if (n != 1)
        cnt[n]++;
}

int main() {
    int a, b;

    cin >> a >> b;

    map<int, int> cnt1, cnt2;
    get_primes(a, cnt1);
    get_primes(b, cnt2);

    for (auto &p : cnt1) {
        if (cnt2.count(p.first) > 0) {
            if (p.second > cnt2[p.first]) {
                p.second -= cnt2[p.first];
                cnt2[p.first] = 0;
            } else {
                cnt2[p.first] -= p.second;
                p.second = 0;
            }
        }
    }

    int qtd1 = 0;
    for (auto &p : cnt1) {
        if (p.second) {
            if (p.first != 2 && p.first != 3 && p.first != 5) {
                qtd1 = -1;
                break;
            } else {
                qtd1 += p.second;
            }
        }
    }
    int qtd2 = 0;
    for (auto &p : cnt2) {
        if (p.second) {
            if (p.first != 2 && p.first != 3 && p.first != 5) {
                qtd2 = -1;
                break;
            } else {
                qtd2 += p.second;
            }
        }
    }

    if (qtd1 == -1 || qtd2 == -1) {
        cout << "-1\n";
    } else {
        cout << qtd1 + qtd2 << "\n";
    }

    return 0;
}
