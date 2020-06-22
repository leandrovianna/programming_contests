#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    int countEven = 0, countOdd = 0;

    while (true) {
        if (countEven < countOdd) {
            n = 2;
        } else {
            n = 3;
        }

        cout << n << endl;

        cin >> r;

        switch (r) {
            case -1:
                return 0;

            case 1: // n + a é impar
                if (n % 2 == 0)
                    countOdd++;
                else
                    countEven++;
                break;

            case 0: // n + a é par
                if (n % 2 == 0)
                    countEven++;
                else
                    countOdd++;
                break;
        }
    }
    return 0;
}
