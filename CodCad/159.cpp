//CodCad - Produto do Intervalo - 159
#include <bits/stdc++.h>
using namespace std;

bool readChar(char &c) {
	c = getchar_unlocked();
	if (c == EOF) return false;
}

inline void writeChar(char c) {
	putchar_unlocked(c);
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

const int N = 1e5+10;

/*
 * Node tem tres valores: 1, 0, -1
 * So precisamos saber se a query resulta em algo positivo,
 * negativo ou em zero. Como é um produto, podemos simplificar
 * e guardar assim.
 */
int tree[4*N]; //segment tree vector

void build(int idx, int l, int r, int* v);
int query(int idx, int l, int r, int a, int b);
void update(int idx, int l, int r, int a, int b, int x);

inline int signal(int x) {
	if (x < 0) return -1;
	else if (x > 0) return 1;
	else return 0;
}

int main() {
	int n, k;
	char op;
	int a, b, tmp;
	int val[N];

	while (readInt(n)) {
		readInt(k);
		for (int i = 0; i < n; i++)
			readInt(val[i]);

		build(0, 1, n, val);

		for (int i = 0; i < k; i++) {
			readChar(op);
			readInt(a);
			readInt(b);
			if (op == 'C')
				update(0, 1, n, a, a, b);
			else {
				tmp = query(0, 1, n, a, b);
				writeChar(tmp < 0 ? '-' : (tmp > 0 ? '+' : '0'));
			}
		}
		writeChar('\n');
	}

	return 0;
}

void build(int idx, int l, int r, int* v) {
	if (l == r) {
		tree[idx] = signal(v[l-1]);
		return;
	}

	int mid = ((r - l) >> 1) + l;
	build(2*idx+1, l, mid, v);
	build(2*idx+2, mid+1, r, v);

	tree[idx] = tree[2*idx+1] * tree[2*idx+2];
}

int query(int idx, int l, int r, int a, int b) {
	if (b < l || a > r) return 1;

	//node interval [l,r] is inside search interval [a,b]
	if (a <= l && r <= b)
		return tree[idx];

	int mid = ((r - l) >> 1) + l;
	int left = query(2*idx+1, l, mid, a, b);
	int right = query(2*idx+2, mid+1, r, a, b);

	return left * right;
}

void update(int idx, int l, int r, int a, int b, int x) {
	if (b < l || a > r) return;

	//node interval [l,r] is inside update interval [a,b]
	if (a <= l && r <= b) {
		tree[idx] = signal(x);
	}

	if (l != r) {
		int mid = ((r - l) >> 1) + l;
		update(2*idx+1, l, mid, a, b, x);
		update(2*idx+2, mid+1, r, a, b, x);

		tree[idx] = tree[2*idx+1] * tree[2*idx+2];
	}
}
