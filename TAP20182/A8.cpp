// TAP 2018/2 - A8 - Symmetrical Pizza
#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

int main() {
    int x, y;

    scanf("%d.%d", &x, &y);

    x = x * 100 + y;

    cout << lcm(x, 36000) / x << endl;

    return 0;
}
