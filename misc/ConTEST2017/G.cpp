#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct {
	int reais;
	int centavos;

} dinheiro;

dinheiro operator+(dinheiro a, dinheiro b) {
	dinheiro r;
	r.reais = a.reais + b.reais;
	int s = a.centavos + b.centavos;

	if (s >= 100) {
		r.centavos = s - 100;
		r.reais++;
	} else {
		r.centavos = s;
	}
	return r;
}

dinheiro operator-(dinheiro a, dinheiro b) {
	dinheiro r;
	r.reais = a.reais - b.reais;
	int s = a.centavos - b.centavos;
	
	if (s < 0) {
		r.reais--;
		r.centavos = 100 + s; //s is negative
	} else {
		r.centavos = s;
	}

	return r;
}

bool operator<(dinheiro a, dinheiro b) {
	return ((a.reais < b.reais) 
			|| (a.reais == b.reais && a.centavos < b.centavos));
}

#define N 100100

int main() {
	int t, n;
	dinheiro r, pago, valores[N];
	dinheiro zero = {0,0};
	int qtd;

	scanf("%d", &t);

	for (int ti = 1; ti <= t; ti++) {
		scanf("%d %d.%d", &n, &r.reais, &r.centavos);

		qtd = 0;
		pago = zero;

		for (int i = 0; i < n; i++) {
			scanf("%d.%d", &valores[i].reais, &valores[i].centavos);
		}

		sort(valores, valores+n);

		for (int i = 0; i < n && !(r - valores[i] < zero); i++) {
			pago = pago + valores[i];
			r = r - valores[i];
			qtd++;
		}

		printf("Caso %d: %d %d.%02d\n", ti, qtd, pago.reais, pago.centavos);
	}
	
	return 0;
}
