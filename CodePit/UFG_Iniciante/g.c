//https://www.urionlinejudge.com.br/judge/pt/problems/view/1103
#include <stdio.h>

#define SECONDS_A_DAY 86400

typedef struct {
	int h, m;
}Hora;

int hora_diff(Hora h1, Hora h2);
int seconds(Hora h);

int main() {
	Hora h1, h2;

	do {
		scanf("%d %d %d %d", &h1.h, &h1.m, &h2.h, &h2.m);
		if (h1.h != 0 || h1.m != 0 || h2.h != 0 || h2.m != 0)
			printf("%d\n", hora_diff(h1, h2));
	} while (h1.h != 0 || h1.m != 0 || h2.h != 0 || h2.m != 0);

	return 0;
}

int hora_diff(Hora h1, Hora h2) {
	int diff = seconds(h2) - seconds(h1);
	if (diff < 0) 
		diff += SECONDS_A_DAY;
	diff /= 60; //convert to minutes
	return diff;
}

int seconds(Hora h) {
	return h.h * 60 * 60 + h.m * 60;
}
