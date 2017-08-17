#include <string.h>
#include <stdio.h>

#define J 1000010
#define A 1000010

int main() {
	int j, a, n, i, qtd;
	char jerseys[J];
	int num[J];
	char c;

	scanf("%d %d", &j, &a);

	memset(num, 0, sizeof(num));

	for (i = 1; i <= j; i++) {
		scanf(" %c", &c);
		jerseys[i] = c;
		num[i] = 1;
	}
	
	qtd = 0;

	for (i = 0; i < a; i++) {
		scanf(" %c %d", &c, &n);

		if (num[n] && c >= jerseys[n]) {
			num[n] = 0;
			qtd++;
		}
	}

	printf("%d\n", qtd);
	return 0;
}
