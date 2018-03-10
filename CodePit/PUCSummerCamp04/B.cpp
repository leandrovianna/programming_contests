//CodePit - D-query - B
//Spoj - D-query - DQUERY
#include <bits/stdc++.h>
using namespace std;

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

const int N = 30010, SQRTN = 180, A = 1111111, M = 200010;
int v[N];
int answers[M];

int nums[A];
int answer = 0;

void mo_add(int pos) {
	nums[v[pos]]++;
	if (nums[v[pos]] == 1)
		answer++;
}

void mo_rem(int pos) {
	nums[v[pos]]--;
	if (nums[v[pos]] == 0)
		answer--;
}

struct query {
	int l, r, seq;
	query() {}
	query(int l, int r, int seq) : l(l), r(r), seq(seq) {}
} queries[M];

int main() {
	ios::sync_with_stdio(false);

	int n, q, a, b;
	readInt(n);
	for (int i = 0; i < n; i++) {
		readInt(v[i]);
	}

	readInt(q);
	for (int i = 0; i < q; i++) {
		readInt(a);
		readInt(b);
		queries[i] = query(a-1, b-1, i);
	}

	int block_size = sqrt(n);

	sort(queries, queries+q, [&](const auto p1, const auto p2) {
				return p1.r / block_size < p2.r / block_size
					|| (p1.r / block_size == p2.r / block_size && p1.l < p2.l);
			});


	int currL = 0, currR = 0;
	answer = 0;

	for (int idx = 0; idx < q; idx++) {
		int l = queries[idx].l;
		int r = queries[idx].r;

		while (currL < l) {
			mo_rem(currL);
			currL++;
		}

		while (currL > l) {
			mo_add(currL-1);
			currL--;
		}

		while (currR <= r) {
			mo_add(currR);
			currR++;
		}

		while (currR-1 > r) {
			mo_rem(currR-1);
			currR--;
		}

		answers[queries[idx].seq] = answer;
	}

	for (int i = 0; i < q; i++) {
		writeInt(answers[i]);
		writeChar('\n');
	}

	return 0;
}
