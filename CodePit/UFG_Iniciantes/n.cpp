#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 100;

bool compara(int x, int y) {
	return (x < y); //ASC
}

/** 
 * Soma Permutada com pos sendo o primeiro
 * elemento na permutação.
 * Nota: passar vetor ordenado.
 * @return Valor de soma nessa permutação.
 */
int spe(int *v, const int n, int pos) {
	int k = 0, sum = 0, max, maxpos, c[N], a;
	for (int i = 0; i < n; i++) c[i] = 0;
	while (k < n) {
		max = 0;
		maxpos = pos;
		c[pos] = 1;
		for (int j = 0; j < n; j++) {
			if (c[j]) continue;

			a = abs(v[pos] - v[j]);
			if (a > max) {
				max = a;
				maxpos = j;
			}
		}

		if (maxpos == pos) break;

		sum += max;
		pos = maxpos;
		k++;
	}

	return sum;
}

int main() {
	int t, n, v[N], max;

	cin >> t;
	for (int t0 = 0; t0 < t; t0++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		sort(v, v+n, compara);
		max = 0;
		for (int i = 0, sum = 0; i < n; i++) {
			sum = spe(v, n, i);
			if (sum > max)
				max = sum;
		}

		cout << "Case " << t0+1 << ": " << max << endl;
	}
	return 0;
}
