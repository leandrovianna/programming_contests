// Live Archive - Different Digits - 6134
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int D = 10;
    int n, m, answer;

    while (cin >> n >> m) {
        answer = 0;
        for (int i = n, j; i <= m; i++) {
            int cnt[D] = {0};
            j = i;
            while (j > 0) {
                cnt[j % 10]++;
                j /= 10;
            }

            answer++;
            for (int d = 0; d < D; d++) {
                if (cnt[d] > 1) {
                    answer--;
                    break;
                }
            }
        }
        
        cout << answer << "\n";
    }
    return 0;
}
