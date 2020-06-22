#include <stdio.h>
#include <string.h>

#define N 10000

int main() {		
	int qtd[N], x, n, m, winner;

	memset(qtd, 0, sizeof(qtd));

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		qtd[x]++;
	}

	m = 0;
	for (int i = 0; i < N; i++) {
		if (qtd[i] > m) {
			m = qtd[i];
			winner = i;
		}
	}

	printf("%d\n", winner);
	return 0;
}
