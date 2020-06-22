// TAP 2018/2 - Looking for the Risk Factor - L8
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int fenwick[N];

void update(int x, int v) {
    while (x < N) {
        fenwick[x] += v;
        x += (x & -x);
    }
}

int query(int x) {
    int s = 0;
    while (x > 0) {
        s += fenwick[x];
        x -= (x & -x);
    }
    return s;
}

int notprime[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q, n, k;

    cin >> q;
    vector<pair<pair<int, int>, int>> queries;
    vector<int> answers;

    for (int i = 0; i < q; i++) {
        cin >> n >> k;
        queries.push_back({{n, k}, i});
        answers.push_back(0);
    }

    sort(queries.begin(), queries.end());

    for (int i = 2; i < N; i++) {
        if (notprime[i] == 0) {
            for (int j = i; j < N; j += i) {
                notprime[j] = i;
            }
        }
    }

    int qi = 0;
    for (int i = 2; i < N; i++) {
        update(notprime[i], 1);

        while (qi < q && i == queries[qi].first.first) {
            answers[queries[qi].second] = 
                query(queries[qi].first.second);
            qi++;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << answers[i] << "\n";
    }

    return 0;
}
