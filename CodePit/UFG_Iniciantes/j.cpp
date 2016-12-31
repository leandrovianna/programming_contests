#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000;

int mod(int x, int n) { return (x < 0) ? n+x : x % n; }

int main() {
	int n, pontos[N], comp[N], qtd;
	long soma[N], dtotal, gap;
	
	while (cin >> n) {
		dtotal = 0;
		for (int i = 0; i < n; i++) {
			cin >> pontos[i];
			dtotal += pontos[i];
			soma[i] = dtotal;
		}

		if (dtotal % 3 != 0) {
			cout << 0 << endl;
			continue;
		}

		gap = dtotal / 3;
		qtd = 0;

		for (int i = 0, x, y; i < n; i++) {
			x = soma[i] + gap;
			y = x + gap;
			if (binary_search(soma, soma+n, x)
					&& binary_search(soma, soma+n, y) )
					qtd++;
		}
		cout << qtd << endl;
	}

	return 0;
}
