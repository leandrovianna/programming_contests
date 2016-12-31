//https://www.urionlinejudge.com.br/judge/pt/problems/view/1221
#include <stdio.h>
#include <math.h>

typedef char bool;

bool is_prime(int p);

int main() {
	int n, i, p;

	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%d", &p);

		if (is_prime(p))
			printf("Prime\n");
		else
			printf("Not Prime\n");
	}
	return 0;
}

bool is_prime(int p) {
	if (p == 2)
		return 1;
	if (p < 2 || p % 2 == 0)
		return 0;

	// Teorema: Seja a um numero natural
	// a nao eh primo se existe um b fator de a
	// e 1 < b <= sqrt(a)

	int i, sqrtp = sqrt(p);

	for (i = 3; i <= sqrtp; ++i)
		if (p % i == 0)
			return 0;

	return 1;
}
