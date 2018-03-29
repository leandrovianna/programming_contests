//Spoj - Pouring Water - POUR1
#include <bits/stdc++.h>
using namespace std;

typedef struct state {
    int a, b, step;

    state() : a(0), b(0), step(0) {}
    state(int a, int b, int step) : a(a), b(b), step(step) {}
} state;

bool operator< (state me, state other) {
    return me.a < other.a || (me.a == other.a && me.b < other.b);
}

bool operator== (state me, state other) {
    return me.a == other.a && me.b == other.b;
}

int bfs(int a, int b, int c) {
    queue<state> q;
    set<state> s;

    q.push({0, 0, 0});
    int ans = 1000000;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        if (s.find(t) != s.end())
            continue;

        s.insert(t);

        if (t.a == c || t.b == c) {
            ans = min(ans, t.step);
            continue;
        }

        q.push(state(min(a, t.a + t.b), max(0, t.b - (a - t.a)), t.step + 1));
        q.push(state(max(0, t.a - (b - t.b)), min(b, t.b + t.a), t.step + 1));
        q.push(state(0, t.b, t.step + 1));
        q.push(state(t.a, 0, t.step + 1));
        q.push(state(a, t.b, t.step + 1));
        q.push(state(t.a, b, t.step + 1));
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t, a, b, c;

    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int gcd = __gcd(a, b);
        if ((a >= c || b >= c) && c % gcd == 0) {
            cout << bfs(a, b, c) << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
