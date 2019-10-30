#include <bits/stdc++.h>
using namespace std;

const int N = 400100, mod = 1000000007;
int n, k;
int64_t poww[N];

const int SEP = 310;
const int M = 400;

int p[N], pn[N], c[N], cn[N], cnt[M], ip[N];
void sort_cyclic_shifts(int s[], const int n) {
    const int alphabet = M;

    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        // fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int ci = 0; ci < classes; ci++) {
            cnt[ci] = 0;
        }
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        // c.swap(cn);
        for (int i = 0; i < N; i++) {
            swap(c[i], cn[i]);
        }
    }
}

void suffix_array_construction(int s[], const int n) {
    // s.push_back(SEP+1);
    // vector<int> sorted_shifts = sort_cyclic_shifts(s);
    
    s[n] = SEP+1;
    memset(cnt, 0, sizeof(cnt));
    memset(p, 0, sizeof(p));
    memset(pn, 0, sizeof(pn));
    memset(c, 0, sizeof(c));
    memset(cn, 0, sizeof(cn));
    sort_cyclic_shifts(s, n+1);

    // sorted_shifts.erase(sorted_shifts.begin());
    for (int i = 0; i < n; i++) {
        p[i] = p[i+1];
    }
}

template<typename T>
bool readInt( T &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true; 
} 

template<typename T>
inline void writeInt(T n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

inline void writeChar(char c) {
    putchar_unlocked(c);
}

int st[N];

int main() {
    poww[0] = 1;
    for (int i = 1; i < N; i++) {
        poww[i] = (poww[i-1] * 365LL) % mod;
    }

    while (readInt(n)) {
        int sz = 0;
        vector<int> pos;

        int d = 0;
        for (int i = 0; i < n; i++) {
            readInt(k);
            d += k;

            pos.push_back(sz);
            for (int j = 0, x; j < k; j++) {
                readInt(x);
                st[sz++] = x;
            }
            st[sz++] = SEP;
        }

        suffix_array_construction(st, sz);

        for (int i = 0; i < sz; i++) {
            ip[p[i]] = i;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (const auto &idx : pos) {
            pq.push({ip[idx], idx});
        }

        int64_t ans = 0;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int idx = t.second;

            ans = (ans + poww[d] * st[idx]) % mod;
            d--;

            idx++;
            if (st[idx] != SEP) {
                pq.push({ip[idx], idx});
            }
        }

        writeInt(ans);
        writeChar('\n');
    }
    return 0;
}
