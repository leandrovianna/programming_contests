//https://www.urionlinejudge.com.br/judge/pt/problems/view/1553
#include <stdio.h>

#define N 1000

int qtd_freq(int [], int, int);
void bubble_sort(int[], int);
void swap(int*, int*);

int main() {
	int n, k, p[N], i;

	while (scanf("%d %d", &n, &k) && (n != 0 || k != 0)) {
		for (i = 0; i < n; i++) {
			scanf("%d", &p[i]);
		}

		printf("%d\n", qtd_freq(p, n, k));
	}
	return 0;
}

int qtd_freq(int p[], int n, int freq) {
	int i, qtd = 0, f = 1;
	bubble_sort(p, n);
	for (i = 1; i < n; ++i) {
		if (p[i] == p[i-1])
			f++;
		else { 
			if (f >= freq)
				qtd++;

			f = 1;
		}
	}

	if (f >= freq)
		qtd++;
	
	return qtd;
}

void bubble_sort(int v[], int tam) {
	int i, j;
	for (i = 0; i < tam-1; ++i)
		for (j = i+1; j < tam; ++j)
			if (v[j] < v[i]) {
				swap(&v[i], &v[j]);
			}
}

void swap(int* n, int* m) {
	int aux = *n;
	(*n) = (*m);
	(*m) = aux;
}
