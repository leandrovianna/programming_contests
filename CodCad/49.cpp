#include <iostream>
using namespace std;

int main() {
	const int N = 1e3;
	int n, m, delta, qtd;
	int v[N];

	cin >> n >> m;
	for (int ni = 0; ni < n; ni++)
		cin >> v[ni];

	qtd = 0;
	for (int i = 0; i < n; i++) {
		while (v[i] != m) {
			qtd++;
			delta = (v[i] < m) ? 1 : -1;

			v[i] += delta;
			if (i != n-1) v[i+1] += delta;
		}
	}

	cout << qtd << endl;
	return 0;
}
