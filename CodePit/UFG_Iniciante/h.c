//https://www.urionlinejudge.com.br/judge/pt/problems/view/1087
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
} Pos;

typedef char bool;

void imprime_movimentos(Pos p1, Pos p2);
bool alcance_dama(Pos p1, Pos p2);

int main() {
	Pos dama, obj;

	do {
		scanf("%d %d %d %d", &dama.x, &dama.y, &obj.x, &obj.y);
		if (dama.x != 0 || dama.y != 0 || obj.x != 0 || obj.y != 0)
			imprime_movimentos(dama, obj);
	} while (dama.x != 0 || dama.y != 0 || obj.x != 0 || obj.y != 0);
	return 0;
}

void imprime_movimentos(Pos p1, Pos p2) {
	int mov;
	if (p1.x == p2.x && p1.y == p2.y)
		mov = 0;
	else if (alcance_dama(p1, p2))
		mov = 1;
	else
		mov = 2;
	printf("%d\n", mov);
}

bool alcance_dama(Pos p1, Pos p2) {
	// same column or line
	if (p1.x == p2.x || p1.y == p2.y)
		return 1;

	if (abs(p2.x - p1.x) == abs(p2.y - p1.y))
		return 1;

	return 0;
}
