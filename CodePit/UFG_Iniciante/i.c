//https://www.urionlinejudge.com.br/judge/pt/problems/view/1240
#include <stdio.h>

int main() {
	int a, b, n, i;

	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);

		while (b != 0) {
			if (a % 10 != b % 10) {
				printf("nao encaixa\n");
				break;
			} else {
				a /= 10;
				b /= 10;
			}
				
		}

		if (b == 0)
			printf("encaixa\n");
	}
	return 0;
}
