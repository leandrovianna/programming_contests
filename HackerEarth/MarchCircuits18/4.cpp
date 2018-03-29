//HackerEarth - Big Number Array
#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif

inline void read(int &n) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if (c == EOF) {
        n = -1;
        return;
    }
    while (!('0' <= c && c <= '9')) {
        if (c == '-') neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
}

inline void writeInt(long long n) {
    register int idx = 20;
    if (n < 0) putchar_unlocked('-');
    n = abs(n);
    char out[21];
    out[20] = ' ';
    do {
        idx--;
        out[idx] = n % 10 + '0';
        n/= 10;
    } while (n);
    do {
        putchar_unlocked(out[idx++]);
    }
    while (out[idx] != ' ');
}


struct interval {
    int lo, hi;
    interval(int lo = 0, int hi = 0) : lo(lo), hi(hi) { }
};

int n;
char seg[4*100005];
int inicio[100015];
int idx[100015];
vector < set  < pair < int, int > > > tree(100015);
vector < set  < pair < int, int > > > lazy(100015);

void build(int no, int lo, int hi) {
    seg[no] = 0;
    if (lo == hi) {
        return ;
    }
    else {
        int mid = (lo + hi) >> 1;
        int x = (no << 1) + 1;
        int y = x + 1;
        build(x, lo, mid);
        build(y, mid+1, hi);
    }
}


void splitAndMergeIntervalos(set < pair < int, int > > &up, set < pair < int, int > > :: iterator &ant, interval &novo, set < pair < int, int > > :: iterator &prox) {
    if (ant != up.end() && ant->second >= novo.lo) {
        interval b_ant = interval(ant->first, ant->second);
        up.erase(ant);

        up.insert({b_ant.lo, novo.lo-1});
        if (novo.hi > b_ant.hi) novo.lo = b_ant.hi+1;
        else {
            if (novo.hi < b_ant.hi) up.insert({novo.hi+1, b_ant.hi});
            return ;
        }
    }
    else if (ant != up.end() && ant->second+1 == novo.lo) {
        novo.lo = ant->first;
        up.erase(ant);
    }

    if (prox != up.end() && prox->first <= novo.hi) {
        interval b_prox = interval(prox->first, prox->second);
        up.erase(prox);

        if (novo.lo == b_prox.lo) {
            if (b_prox.hi == novo.hi) return;
            up.insert({novo.hi+1, b_prox.hi});
            return;
        }
        else {
            up.insert({novo.hi+1, b_prox.hi});
            novo.hi = b_prox.lo-1;
        }
    }
    else if (prox != up.end() && novo.hi+1 == prox->first) {
        novo.hi = prox->second;
        up.erase(prox);
    }

    if (novo.lo <= novo.hi && novo.lo >= 0 && novo.hi <= 1000000005) {
        up.insert({novo.lo, novo.hi});
    }
}

void adcIntervalo(set < pair < int, int > > &up, interval novo) {
    set < pair < int, int > > :: iterator at = up.lower_bound({novo.lo, -1}), aux, ant, prox;
    ant = prox = up.end();
    interval b = novo;
    while (at != up.end() && at->second <= novo.hi) {
        aux = at;
        aux++;

        if (novo.lo < at->first) {
            up.insert({novo.lo, at->first-1});
            novo.lo = at->second+1;
        }
        else if (novo.lo == at->first) {
            novo.lo = at->second+1;
        }

        up.erase(at);
        at = aux;
    }

    prox = at;

    if (at != up.begin()) {
        ant = at;
        ant--;
    }
    //cout << ant->first << " " << ant->second << " / " << prox->first << " " << prox->second << endl;
    splitAndMergeIntervalos(up, ant, novo, prox);
}

void update(int no, int lo, int hi, int x, int y, char novo) {
    if (x > y || x <= 0 || x > n || y <= 0 || y > n) return ;
    if (x <= lo && hi <= y) {
        seg[no] = novo;
        return ;
    }
    int mid = (lo + hi) >> 1;
    int ax = (no << 1) + 1;
    int ay = ax + 1;
    if (mid >= x) update(ax, lo, mid, x, y, novo);
    if (mid+1 <= y) update(ay, mid+1, hi, x, y, novo);
}


char query(int no, int lo, int hi, int x, int y) {
    if (x > y || x <= 0 || x > n || y <= 0 || y > n) return 0;
    if (x <= lo && hi <= y) {
        return seg[no];
    }
    int mid = (lo + hi) >> 1;
    int ax = (no << 1) + 1;
    int ay = ax + 1;
    char ansA = 0, ansB = 0;
    if (mid >= x)  ansA = query(ax, lo, mid, x, y);
    if (mid+1 <= y) ansB = query(ay, mid+1, hi, x, y);
    return (ansA || ansB);
}

void updatePos(int lo, interval novo) {
    if (query(0, 1, n, lo, lo)) {
        for (auto &it : lazy[idx[lo]]) {
            adcIntervalo(tree[lo], interval(it.first, it.second));
        }
    }
    adcIntervalo(tree[lo], novo);
    update(0, 1, n, lo, lo, 0);
}

void update(int lo, int hi, interval novo) {
    if (idx[lo] == idx[hi]) {
        while (lo <= hi) {
            updatePos(lo++, novo);
        }
    }
    else {
        int id = idx[lo];
        while (id == idx[lo]) {
            updatePos(lo++, novo);
        }
        int x = idx[lo];
        int y = idx[hi];
        while (x != y) {
            adcIntervalo(lazy[x], novo);
            lazy[x].clear();
            update(0, 1, n, inicio[x], inicio[x+1]-1, 0);
            lo = inicio[++x];
        }
        while (lo <= hi) {
            updatePos(lo++, novo);
        }
    }
}

void query(int x, set < pair < int, int > > &ans) {
    if (query(0, 1, n, x, x)) {
        for (auto &it : lazy[idx[x]]) {
            adcIntervalo(tree[x], interval(it.first, it.second));
        }
        update(0, 1, n, x, x, 0);
    }
    ans = tree[x];
}

void print(string str) {
    for (auto i : str) {
        putchar_unlocked(i);
    }
}

int main() {
    int t, q, x, y, l, r, op;
    read(t);

    while (t--) {
        read(n);
        read(q);

        build(0,1,n);

        int r = 1;
        int id = 0;
        inicio[0] = 1;

        for (int i = 1; i <= n;) {
            for (int j = 0; j < r; j++) {
                tree[i].clear();
                tree[i].insert({0, 1000000005});
                lazy[i].clear();
                idx[i++] = id;
            }
            id++;
            inicio[id] = i;
        }

        while (q--) {
            read(op);
            if (op == 1) {
                read(x);
                read(y);
                read(l);
                read(r);
                update(x, y, interval(l+1, r+1));
            }
            else {
                read(x);
                read(y);
                set < pair < int, int > > ans1, ans2;
                query(x, ans1);
                query(y, ans2);
                if (ans1.size() == ans2.size() && ans1 == ans2) print("YES\n");
                else print("NO\n");
            }
        }
    }
    return 0;
}
