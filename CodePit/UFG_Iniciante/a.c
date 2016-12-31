//https://www.urionlinejudge.com.br/judge/pt/problems/view/1387 
#include <stdio.h>

int main() {
	int filhos, filhas;

	do {
		scanf("%d %d", &filhos, &filhas);
		if (filhos != 0 || filhas != 0)
			printf("%d\n", filhos + filhas);
	} while (filhos != 0 || filhas != 0);
	return 0;
}
