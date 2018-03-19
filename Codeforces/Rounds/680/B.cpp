//Codeforces - Bear and Finding Criminals - 680B Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    const int N = 110;
    int n, x;
    int criminal[N];

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> criminal[i];
    }

    int answer = 0;
    x--;

    if (criminal[x] == 1)
        answer++;

    for (int d = 1; d <= max(x, n-x); d++) {
        int bcd = 0, count = 0;

        if (x - d >= 0)
            bcd += criminal[x-d], count++;

        if (x + d < n)
            bcd += criminal[x+d], count++;

        // count - qtd de cidades a distancia d
        // bcd - qtd de criminosos a distancia d
        if (bcd > 0 && count == bcd)
            answer += bcd;
    }

    cout << answer << endl;

    return 0;
}
