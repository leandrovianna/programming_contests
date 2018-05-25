#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n, x, sum, qtd;

    cin >> n;
    sum = 0;
    qtd = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x >= 90) {
            sum += x;
            qtd++;
        }
    }

    int ans = sum * 1000 / qtd;

    int ans2 = ans - (ans / 1000) * 1000;
    if (ans2 % 10 >= 5) {
        ans2 += 10;
    }

    ans2 /= 10;

    cout << (ans / 1000) << "." << ans2  << endl;
    return 0;
}
