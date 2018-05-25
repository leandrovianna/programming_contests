// Codechef - May Challenge 2018 - Mighty Friend - MYYFRI
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;

    cin >> t;
    while (t--) {
        cin >> n >> k;

        priority_queue<int> pq1, pq2;
        int score1 = 0, score2 = 0;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            if (i & 1) {
                pq1.push(-x);
                score2 += x;
            }
            else {
                pq2.push(x);
                score1 += x;
            }
        }

        for (int i = 0; i < k; i++) {
            if (!pq1.empty() && !pq2.empty()) {
                if (-pq1.top() >= pq2.top()) {
                    break;
                }


                score2 -= -pq1.top();
                score2 += pq2.top();

                score1 -= pq2.top();
                score1 += -pq1.top();

                pq1.pop();
                pq2.pop();
            }
        }

        cout << (score2 > score1 ? "YES" : "NO") << endl;
    }
    return 0;
}
