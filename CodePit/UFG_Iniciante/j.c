//https://www.urionlinejudge.com.br/judge/pt/problems/view/1607
#include <stdio.h>

#define N 10000+1
#define QTD_LETTERS ('z' - 'a' + 1)

int numero_operacoes(char s1[], char s2[]);

int main() {
	int n, i;
	char s1[N], s2[N];

	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%s %s", s1, s2);
		printf("%d\n", numero_operacoes(s1, s2));
	}
	return 0;
}

int numero_operacoes(char s1[], char s2[]) {
	int i = 0, op, soma = 0;
	while (s1[i]) {
		op = (s2[i] - s1[i]);
		if (op < 0)
			op += QTD_LETTERS;
		soma += op;
		i++;
	}
	return soma;
}
