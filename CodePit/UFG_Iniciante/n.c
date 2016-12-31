//https://www.urionlinejudge.com.br/judge/pt/problems/view/1430
#include <stdio.h>

#define N (200+1)

#define W 1000000
#define H 500000
#define Q 250000
#define E 125000
#define S 62500
#define T 31250 
#define X 15625

int compassos_corretos(char[]);
int nota(char);

int main() {
	char s[N];

	while (scanf("  %[^\n]s", s) && (s[0] != '*')) {
		printf("%d\n", compassos_corretos(s));
	}
	return 0;
}

int compassos_corretos(char s[]) {
	int i = 1, corretos = 0, soma = 0;

	while (s[i]) {
		if (s[i] == '/') {
			if (soma == W)
				corretos++;

			soma = 0;
		} else {
			soma += nota(s[i]);
		}

		i++;
	}

	return corretos;
}

int nota(char n) {
	switch (n) {
		case 'W': return W;
		case 'H': return H;
		case 'Q': return Q;
		case 'E': return E;
		case 'S': return S;
		case 'T': return T;
		case 'X': return X;
	}
	return 0;
}
