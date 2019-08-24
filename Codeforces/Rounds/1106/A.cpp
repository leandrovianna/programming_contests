// Codeforces - Lunar New Year and Cross Counting - 1106A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    const int N = 510;
    char m[N][N];

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    int answer = 0;
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (m[i][j] == 'X' && m[i-1][j-1] == 'X'
                    && m[i-1][j+1] == 'X' && m[i+1][j-1] == 'X'
                    && m[i+1][j+1] == 'X') {
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
