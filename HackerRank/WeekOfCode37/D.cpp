#include <bits/stdc++.h>
using namespace std;

const int N = 100100, SQN = 500;

int lines[SQN][SQN];
int q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    char op;
    int n, a, b;
    int64_t answer;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> op;

        switch (op) {
            case '?':
                cin >> a;
                answer = q[a];
                for (int i = 1; i < SQN; i++) {
                    answer += lines[i][a % i];
                }
                cout << answer << "\n";
                break;
            case '+':
                cin >> a >> b;

                if (a >= SQN) {
                    for (int j = b % a; j < N; j += a)
                        q[j]++;
                } else {
                    lines[a][b % a]++;
                }
                break;
            case '-':
                cin >> a >> b;

                if (a >= SQN) {
                    for (int j = b % a; j < N; j += a)
                        q[j]--;
                } else {
                    lines[a][b % a]--;
                }
                break;
        }
    }
    return 0;
}
