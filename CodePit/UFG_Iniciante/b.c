//https://www.urionlinejudge.com.br/judge/pt/problems/view/1161 
#include <stdio.h>

typedef unsigned long long int ulong;

ulong fat(int n);

int main() {
	int n, m, ret;
	ulong soma;

	while (scanf("%d %d", &m, &n) != EOF)
		printf("%llu\n", fat(m) + fat(n));
	return 0;
}

ulong fat(int n) {
	int i;
	ulong fat = 1;
	for (i = 2; i <= n; ++i) {
		fat *= i;
	}
	return fat;
}
