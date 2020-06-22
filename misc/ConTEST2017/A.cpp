#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 1000100

int main() {
	int t, n, c, v;
	int notas[N], ultimo, qtd;

	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cin >> n >> c >> v;

		for (int i = 0; i < n; i++)
			scanf("%d", &notas[i]);

		sort(notas, notas+n);

		qtd = 0;
		for (int i = 0; i < n; i++)
			if (notas[i] >= c) qtd++;

		ultimo = notas[n-v];

		cout << "Caso " << ti << ": " << qtd << " " << ultimo << endl;
	}
	return 0;
}
