#include <iostream>
using namespace std;

#define N 10000
#define M N
#define INF 1000000000

inline int max(int a, int b) {
	return (a > b) ? a : b;
}

int bs(int v[], int n, int x) {
	int ini = 0, fim = n-1, meio;

	while (ini <= fim) {
		meio = (ini+fim)/2;

		if (v[meio] == x)
			return meio;
		else if (v[meio] > x)
			fim = meio-1;
		else if (v[meio] < x)
			ini = meio+1;
	}

	return min(ini, fim);
}

int main() {
	int n, m, a[N], f[N], o;

	cin >> n >> m;
	a[0] = 0;
	for (int i = 1; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		cin >> f[i];

	for (int i = 0; i < m; i++, cout << ' ') {
		cin >> o;
		int x = bs(a, n, o);

		cout << f[x];
	}

	return 0;
}
