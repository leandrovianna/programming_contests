#include <iostream>
#include <algorithm>
using namespace std;

#define N 100100

int main() {
	int t, n, qtd;
	long v[N];

	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> v[i];

		sort(v, v+n);

		qtd = 1;
		for (int i = 1; i < n; i++)
			if (v[i] != v[i-1]) qtd++;

		cout << "Caso " << ti << ": " << qtd << endl;
	}
	return 0;
}
