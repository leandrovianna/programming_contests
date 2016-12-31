//https://www.urionlinejudge.com.br/judge/pt/problems/view/1548
#include <iostream>
#include <algorithm>
using namespace std;

int elementos_iguais(const int v1[], const int v2[], const int N);
inline bool compara(int a, int b) { return (a >= b); }

int main() {
	const int M = 1000;
	int m, p[M], n, aux[M];	

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> p[j];
			aux[j] = p[j]; 
		}

		sort (aux, aux+m, compara);
		cout << elementos_iguais(p, aux, m) << endl;
	}
	return 0;
}

int elementos_iguais(const int v1[], const int v2[], const int N) {
	int qtd = 0;
	for (int i = 0; i < N; i++)
		if (v1[i] == v2[i])
			qtd++;
	return qtd;
}
