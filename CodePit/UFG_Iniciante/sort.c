
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
