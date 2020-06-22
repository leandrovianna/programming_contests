#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

const int N = 110, M = 1100;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a,b)); }

typedef struct {
	int n, d;
} frac;

frac operator+(const frac a, const frac b) {
	frac c;
	if (a.d == b.d) {
		c.d = a.d;
		c.n = a.n + b.n;
	} else {
		c.d = lcm(a.d, b.d);
		c.n = (c.d / a.d) * a.n + (c.d / b.d) * b.n;
	}

	int f = gcd(c.n, c.d);
	c.n /= f;
	c.d /= f;

	return c;
}

frac operator/(const frac a, const frac b) {
	frac c;
	c.n = a.n * b.d;
	c.d = a.d * b.n;

	int f = gcd(c.n, c.d);
	c.n /= f;
	c.d /= f;

	return c;
}

bool operator==(const frac a, const frac b) {
	return (a.n == b.n && a.d == b.d);	
}

int mod(int x, int m) {
	if (x < 0) return m+x;
	else return x % m;
}

frac mean(frac a[][N], const int h, const int w, const int i, const int j) {

	frac r = {1,1};
	for (int k = mod(i-1,h); k != mod(i+2,h); k = mod(k+1, h)) {
		for (int l = mod(j-1,w); l != mod(j+2,w); l = mod(l+1,w)) {
			r = r + a[k][l];
		}
	}

	frac f = {9,1};
	r = r / f;
	return r;
}

void blur(frac m[][N], const int h, const int w) {
	frac cpy[N][N];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cpy[i][j] = m[i][j];

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			m[i][j] = mean(cpy, h, w, i, j);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	frac m[N][N];
	// bool inv[M][M];
	set<string> s;
	string str;
	int w, h, b;

	// for (int i = 0; i < M; i++)
	// 	memset(inv[i], 0, sizeof(inv[i]));

	cin >> w >> h >> b;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> m[i][j].n, m[i][j].d = 1;

	while (b--) blur(m, h, w);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			str = to_string(m[i][j].n) + "/" + to_string(m[i][j].d);
			s.insert(str);
		}
	}

	cout << s.size() << endl;

	return 0;
}
