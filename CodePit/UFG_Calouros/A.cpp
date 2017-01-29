#include <iostream>
#include <cstdio>
using namespace std;

int bs(const long v[], const int n, const long x) {
	int ini = 0, fim = n-1, half, i = -1;

	while (ini <= fim) {
		half = (ini+fim)/2;

		if (v[half] == x) {
			i = half;
			fim = half-1;
		}
		else if (v[half] < x) ini = half+1;
		else if (v[half] > x) fim = half-1;
	}
	return i;
}

int main() {
	const int N = 100000;
	int n, m;
	long v[N], q;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < m; i++) {
		scanf("%d", &q);
		printf("%d\n", bs(v, n, q));
	}

	return 0;
}
