//Lib - Matrix Power
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 4

struct Matrix { int64_t mat[MAX_N][MAX_N]; };

Matrix matMul(Matrix a, Matrix b, int64_t m) {
	Matrix ans;
	int i, j, k;
	for (i = 0; i < MAX_N; i++)
		for (j = 0; j < MAX_N; j++)
			for (ans.mat[i][j] = k = 0; k < MAX_N; k++)
				ans.mat[i][j] = (ans.mat[i][j] +
						((a.mat[i][k] % m * b.mat[k][j] % m) % m)) % m;

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

	return 0;
}
