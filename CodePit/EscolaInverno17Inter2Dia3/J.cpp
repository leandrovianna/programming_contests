#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

#define MAX_N 2

struct Matrix { i32 mat[MAX_N][MAX_N]; };

Matrix matMul(Matrix a, Matrix b, int m) {
	Matrix ans; 
	int i, j, k;
	for (i = 0; i < MAX_N; i++)
		for (j = 0; j < MAX_N; j++)
			for (ans.mat[i][j] = k = 0; k < MAX_N; k++)
				ans.mat[i][j] = (ans.mat[i][j] + 
						((a.mat[i][k] % m * b.mat[k][j] % m) % m)) % m;

	return ans; 
}

Matrix matPow(Matrix base, i32 p, int m) {
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
	i32 n;
	int m;
	Matrix fib, r;
	
	while (cin >> n >> m) {
		fib.mat[0][0] = fib.mat[0][1] = fib.mat[1][0] = 1;
		fib.mat[1][1] = 0;

		r = matPow(fib, n, pow(2, m));

		cout << r.mat[0][1] << endl;
	}

	return 0;
}
