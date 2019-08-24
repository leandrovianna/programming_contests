// Codeforces - NN and the Optical Illusion - 1100C
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    constexpr double PI = acos(-1);

    double alpha = (PI * (n - 2)) / n;

    double R = r * cos(alpha / 2.0) / (1 - cos(alpha / 2.0));

    cout << fixed << setprecision(10);
    cout << R << endl;
    return 0;
}
