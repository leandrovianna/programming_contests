//CodePit - Onibus - C
//URI - Onibus - 1474
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2;

struct Matrix { int64_t mat[MAX_N][MAX_N]; };

Matrix matMul(Matrix a, Matrix b, int64_t mod) {
	Matrix ans;
	int i, j, k;
	int64_t x, y;
	for (i = 0; i < MAX_N; i++)
		for (j = 0; j < MAX_N; j++)
			for (ans.mat[i][j] = k = 0; k < MAX_N; k++) {
				x = a.mat[i][k] % mod;
				y = b.mat[k][j] % mod;
				ans.mat[i][j] += (x * y) % mod;
				ans.mat[i][j] %= mod;
			}

	return ans;
}

Matrix matPow(Matrix base, int64_t p, int64_t m) {
	Matrix ans;
	int i, j;
	for (i = 0; i < MAX_N; i++)
		for (j = 0; j < MAX_N; j++)
			ans.mat[i][j] = (i == j);

	while (p) {
		// iterative version of Divide & Conquer exponentiation
		// check if p is odd (last bit is on)
		if (p & 1)
			ans = matMul(ans, base, m);

		base = matMul(base, base, m); // square the base
		p >>= 1; // divide p by 2
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);

	const int64_t mod = 1000000;
	int64_t n, l, k;

	while (cin >> n >> k >> l) {
		Matrix m = { {k, l, 1, 0} };

		Matrix r = matPow(m, n/5LL, mod);

		cout << setw(6) << setfill('0');
		cout << r.mat[0][0] << endl;
	}

	return 0;
}
