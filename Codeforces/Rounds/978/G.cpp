// Codeforces - G - Petya's Exams - 978G
#include <bits/stdc++.h>
using namespace std;

const int N = 110;

struct exam {
    int s, d, c, i;
    exam() {}
    exam(int s, int d, int c, int i)
        : s(s), d(d), c(c), i(i)
    {};
};
bool operator> (const exam e1, const exam e2) {
    return e1.d > e2.d;
}

int d[N];
vector<exam> s[N];

int main() {
    int n, m;

    cin >> n >> m;
    exam e;
    for (int i = 0; i < m; i++) {
        cin >> e.s >> e.d >> e.c;
        e.i = i+1;
        d[e.d] = i+1;
        s[e.s].push_back(e);
    }

    vector<int> ans;
    priority_queue<exam, vector<exam>, greater<exam> > pq;
    bool sorry_petya = false;
    for (int i = 1; i <= n; i++) {
        for (const auto &ex : s[i]) {
            pq.push(ex);
        }

        if (d[i] > 0) {
            if (d[i] == m+1)
                ans.push_back(m+1);
            else {
                sorry_petya = true;
                break;
            }
        } else {
            if (!pq.empty()) {
                e = pq.top();
                pq.pop();

                ans.push_back(e.i);
                if (e.c > 1) {
                    e.c--;
                    pq.push(e);
                } else {
                    // finish study for this exam
                    d[e.d] = m+1;
                }
            } else {
                ans.push_back(0);
            }
        }
    }

    if (sorry_petya == false) {
        for (const auto &i : ans) {
            cout << i << " ";
        }
    } else {
        cout << -1;
    }
    cout << endl;

    return 0;
}
