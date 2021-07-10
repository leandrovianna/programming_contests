#include <bits/stdc++.h>
using namespace std;

int N, M, A[100000], B[100000], C[100000], inB[100010];
set<int> inAC[100010];
set<int> trip;
set<int> rem, withB0;
deque<int> res;
int pos[100010];
int delta = 0;

void construct() {
    if (rem.size() == 0) {
        return;
    }
    // cout << "rem: ";
    // for (int j : rem) cout << j << " "; cout << endl;
    // cout << "withB0: ";
    // for (int j : withB0) cout << j << " "; cout << endl;
    assert(withB0.size() > 0);
    int x = *withB0.begin();
    set<int> remv;
    for (int tocheck : inAC[x]) {
        assert(trip.count(tocheck));
        remv.insert(tocheck);
        inB[B[tocheck]]--;
        if (!inB[B[tocheck]]) withB0.insert(B[tocheck]);
        trip.erase(tocheck);
        // inAC[A[tocheck]].erase(tocheck);
        // inAC[C[tocheck]].erase(tocheck);
    }
    for (int i : remv) {
        inAC[A[i]].erase(i);
        inAC[C[i]].erase(i);
    }
    rem.erase(x);
    withB0.erase(x);
    construct();
    int sat = 0;
    for (int tocheck : remv) {
        if (C[tocheck] == x) swap(A[tocheck], C[tocheck]);
        if (pos[B[tocheck]] < pos[C[tocheck]]) sat++;
    }
    if (sat * 2 >= remv.size()) {
        delta++;
        pos[x] = -delta;
        res.push_front(x);
    }
    else {
        pos[x] = res.size() - delta;
        res.push_back(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("insider.in", "r", stdin);
    freopen("insider.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> A[i] >> B[i] >> C[i];

    for (int i = 0; i < M; i++) {
        inB[B[i]]++;
        inAC[A[i]].insert(i);
        inAC[C[i]].insert(i);
        trip.insert(i);
    }
    for (int i = 0; i < N; i++) {
        rem.insert(i + 1);
        if (!inB[i + 1])
            withB0.insert(i + 1);
    }

    construct();

    bool first = true;
    for (int i : res) {
        if (!first) cout << " ";
        first = false;
        cout << i;
    }
    cout << "\n";

    return 0;
}
