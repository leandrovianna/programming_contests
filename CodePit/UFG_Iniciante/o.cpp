#include <iostream>
#include <algorithm>
using namespace std;

void verificar_jogadas(long a[], int n, long b[], int m);
int search(long v[], const int N, const long x);
bool soma_sub_seq(long s[], int inicio, int fim, long valor);
bool menor(long a, long b) { return (a < b); };

int main() {
	const int M = 10000; //10^4
	const int N = 1000; //10^3
	int n, m; 
	long* a = (long*) malloc(sizeof(long) * N),
		* b = (long*) malloc(sizeof(long) * M);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < m; ++i)
		cin >> b[i];
		
	verificar_jogadas(a, n, b, m);

	free(a);
	free(b);
	return 0;
}

void verificar_jogadas(long a[], int n, long b[], int m) {
	// percorrer a sequencia b
	// 1st: verificar existencia de elemento de A
	// 2nd: caso contrario, verificar em subsequencia soma possivel
	
	// antes, ordenar A para a binary search
	sort (a, a+n, menor);

	for (int i = 0; i < m; i++) {
		// 1st
		if (search (a, n, b[i]) == -1) { 
			// 2nd
			if (!soma_sub_seq(b, 0, i, b[i])) {
				cout << b[i] << endl; // jogada invalida, valor nao possivel para B
				return ;
			}
		}
	}

	cout << "sim" << endl;
}

// Verifica se algum par da sub-sequencia somado eh igual ao valor
bool soma_sub_seq(long s[], int inicio, int fim, long valor) {
	int k, v;

	sort (s + inicio, s + fim, menor);

	for (int i = inicio; i < fim; i++) {
		v = valor - s[i]; // valor = s[i] + v
		k = search(s + inicio, fim, v);
		if (k != -1)
			break;
	}

	return (k != -1);
}

int search(long v[], const int N, const long x) {
	int i = 0, n = N-1, h;
	
	while (i != n && n >= 0) {
		h = (i + n) / 2;
		// cout << "half = " << h << endl;
		if (v[h] == x) return h;
		else if (v[h] > x) n = h-1;
		else i = h+1;
	}

	return (v[i] == x) ? i : -1;
}
