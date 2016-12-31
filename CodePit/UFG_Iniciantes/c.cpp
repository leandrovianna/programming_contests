#include <iostream>
using namespace std;

typedef unsigned long long ullong;

const int N = 500;

ullong suml(long m[][N], int n, int l) {
	ullong sum = 0;
	for (int i = 0; i < n; i++)
		sum += m[l][i];
	return sum;
}

ullong sumc(long m[][N], int n, int c) {
	ullong sum = 0;
	for (int i = 0; i < n; i++)
		sum += m[i][c];
	return sum;
}

ullong sumdp(long m[][N], int n) {
	ullong sum = 0;
	for (int i = 0; i < n; ++i)
		sum += m[i][i];
	return sum;
}

ullong sumds(long m[][N], int n) {
	ullong sum = 0;
	for (int i = 0, j = n-1; i < n; ++i, j--)
		sum += m[i][j];
	return sum;
}

int finish(long long x) {
	cout << x << endl;
	return 0;
}

int main() {
	long m[N][N];
	ullong sum_empty, sum, sum_tmp;
    long long x = 0;
	int n, l, c;

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> m[i][j];
			if (m[i][j] == 0) {
				l = i;
				c = j;
			}
		}

	if (n == 1)
		return finish(1);

	sum_empty = sumc(m, n, c);
	if (l == c) {
		sum_tmp = sumdp(m, n);
		if (sum_tmp != sum_empty)
			return finish(-1);

		sum = suml(m, n, (l+1) % n);
	} else {
		sum = sumdp(m, n);
	}

	if (l == n-1-c) {
		sum_tmp = sumds(m, n);
		if (sum_tmp != sum_empty)
			return finish(-1);

	} else {
		sum_tmp = sumds(m, n);
		if (sum_tmp != sum)
			return finish(-1);
	}

	for (int i = 0; i < n; ++i) {
		if (i != l) {
			sum_tmp = suml(m, n, i);

			if (sum_tmp != sum)
				return finish(-1);
		}

		if (i != c) {
			sum_tmp = sumc(m, n, i);

			if (sum_tmp != sum)
				return finish(-1);
		}
	}


	x = sum - sum_empty;
	return finish((x > 0) ? x : -1);
}
