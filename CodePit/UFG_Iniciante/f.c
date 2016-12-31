//https://www.urionlinejudge.com.br/judge/pt/problems/view/1329
#include <stdio.h>

#define N 10000

int main() {
	int r[N], n, i, maria, joao;

	do {
		scanf("%d", &n);
	
		if (n != 0) {
			joao = 0;
			maria = 0;

			for (i = 0; i < n; i++) {
				scanf("%d", &r[i]);

				if (r[i] == 0)
					maria++;
				else
					joao++;
			}

			printf("Mary won %d times and John won %d times\n", maria, joao);
		}
	} while (n != 0);

	return 0;
}
