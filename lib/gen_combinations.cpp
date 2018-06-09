#include <bits/stdc++.h>
using namespace std;

void gen_comb(vector<int> a, int r) {
    assert(r <= (int) a.size());

    vector<bool> v(a.size());
    fill(v.begin(), v.begin() + r, true);

    do {
        for (size_t i = 0; i < v.size(); i++) {
            if (v[i]) {
                cout << a[i] << " ";
            }
        }
        cout << "\n";

    } while (prev_permutation(v.begin(), v.end()));
}

int main() {
    const int N = 50, R = 4;
    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        a[i] = rand();
    }

    gen_comb(a, R);
    return 0;
}
