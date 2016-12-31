#include <iostream>
#include <algorithm>
using namespace std;

void join (int* v, const int n, const int i, const int j) {
	int ti = v[i], tj = v[j];

	for (int k = 0; k < n; ++k) {
		// todos q estao no time do j
		// devem estar no time do i
		if (v[k] == tj)
			v[k] = ti;
	}
}

int main() {
	const int N = 1000;
	int v[N], n, m, i, j, teams;

	cin >> n >> m;

	// inicializando vetor de times
	// i - aluno | v[i] - time do aluno i
	for (int k = 0; k < n; ++k)
		v[k] = k+1;

	for (int k = 0; k < m; ++k) {
		cin >> i >> j; 
		// convertendo de 1 a N para 0 N-1
		i--;
		j--;

		join(v, n, i, j);
	}

	sort(v, v+n);
	teams = 1;
	for (int k = 1; k < n; ++k)
		if (v[k-1] != v[k])
			teams++;

	cout << teams << endl;
	return 0;
}
