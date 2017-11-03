//CodCad - Caixas de Moedas - 204
#include <bits/stdc++.h>
using namespace std;

bool readChar(char &c) {
	c = getchar_unlocked();
	if (c == EOF) return false;
	else return true;
}

inline void writeChar(char c) {
	putchar_unlocked(c);
}

template<typename T>
inline bool readInt(T &n) {
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

template<typename T, typename... Args>
inline bool readInt(T &n, Args&... args) {
	bool r = readInt(n);
	r |= readInt(args...);
	return r;
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

const int N = 1e5+10;

int n, tree[4*N], lazy[4*N], v[N];

void build(int idx, int l, int r) {
	if (l == r) tree[idx] = v[l];
	else {
		int mid = (l + r) >> 1;

		build(2*idx+1, l, mid);
		build(2*idx+2, mid+1, r);
		tree[idx] = tree[2*idx+1] + tree[2*idx+2];
	}
}


void lazy_update(int idx, int l, int r) {
	tree[idx] = (r - l + 1) * lazy[idx];

	// push
	if (l != r)
		lazy[2*idx+1] = lazy[2*idx+2] = lazy[idx];

	lazy[idx] = 0;
}

void update(int idx, int l, int r, int x, int y, int k) {
	if (lazy[idx] > 0)
		lazy_update(idx, l, r);

	if (x > r || y < l) return;

	if (x <= l && r <= y) {
		lazy[idx] = k;
		lazy_update(idx, l, r);
		return;
	}

	int mid = (l + r) >> 1;
	update(2*idx+1, l, mid, x, y, k);
	update(2*idx+2, mid+1, r, x, y, k);
	tree[idx] = tree[2*idx+1] + tree[2*idx+2];
}

int query(int idx, int l, int r, int x, int y) {
	if (x > r || y < l) return 0; 

	if (lazy[idx] > 0)
		lazy_update(idx, l, r);

	if (x <= l && r <= y) return tree[idx];

	int mid = (l + r) >> 1;

	return query(2*idx+1, l, mid, x, y)
		+ query(2*idx+2, mid+1, r, x, y);
}

int main() {
	ios::sync_with_stdio(false);
	
	int q, a, b, k, op;
	readInt(n);
	readInt(q);
	for (int i = 1; i <= n; i++) {
		readInt(v[i]);
	}

	build(0, 1, n);

	for (int i = 0; i < q; i++) {
		readInt(op);
		readInt(a);
		readInt(b);
		if (op == 1) {
			readInt(k);
			update(0, 1, n, a, b, k);
		}
		else {
			writeInt(query(0, 1, n, a, b));
			writeChar('\n');
		}
	}

	return 0;
}
