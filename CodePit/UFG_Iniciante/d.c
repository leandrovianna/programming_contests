//https://www.urionlinejudge.com.br/judge/pt/problems/view/1171
#include <stdio.h>

#define N (40000)

void merge_sort(int v[], int inicio, int fim);

int main() {
	int n, v[N], i, value, repeat;

	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}

	merge_sort(v, 0, n-1);

	value = v[0];
	repeat = 1;
	for (i = 1; i < n; ++i) {
		if (v[i] == value) {
			repeat++;
		} else {
			printf("%d aparece %d vez(es)\n", value, repeat);
			value = v[i];
			repeat = 1;
		}
	}

	printf("%d aparece %d vez(es)\n", value, repeat);

	return 0;
}

void merge_sort(int v[], int inicio, int fim) {
	if (inicio == fim) return;

	int metade = (inicio + fim) / 2;
	int i, j, aux[N], k;

	merge_sort(v, inicio, metade);
	merge_sort(v, metade+1, fim);

	j = metade + 1;
	k = 0;

	for (i = inicio; i <= metade; ++i) {

		while (j <= fim && v[j] < v[i]) {
			aux[k] = v[j];
			k++;
			j++;
		}

		aux[k] = v[i];
		k++;
	}

	while (j <= fim) {
		aux[k] = v[j];
		j++;
		k++;
	}

	for (i = inicio; i <= fim; ++i) {
		v[i] = aux[i - inicio];
	}
}

