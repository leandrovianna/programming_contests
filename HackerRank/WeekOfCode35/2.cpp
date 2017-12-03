#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;

int main() {
    int m, n, k;
    cin >> n >> m >> k;
    int a[N][N];
    a[0][0] = m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (i == j) a[i][j] = a[i-1][j-1] + k;
            else if (i > j) a[i][j] = a[i-1][j] - 1;
            else if (i < j) a[i][j] = a[i][j-1] - 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
            cout << " \n"[j == n-1];
        }
    }
    return 0;
}
