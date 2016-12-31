#include <stdio.h>

int main() {
	int cod1, cod2, units1, units2;
	double preco1, preco2;
	scanf("%d %d %lf", &cod1, &units1, &preco1);
	scanf("%d %d %lf", &cod2, &units2, &preco2);
	printf("VALOR A PAGAR: R$ %.2lf\n", (units1 * preco1) + (units2 * preco2));
	return 0;
}
