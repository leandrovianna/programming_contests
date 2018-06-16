#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int64;

typedef struct {
	int64 x, y;
} ponto;

int main() {
	const int64 T = 1e5, C = 1e5;
	int64 t, c;
	ponto p[T];
	int64 raios[C], PONTOS[C];

	cin >> c >> t;
	for (int64 i = 0; i < c; i++) {
		cin >> raios[i];
		PONTOS[i] = c - i;
	}

	for (int64 i = 0; i < t; i++) {
		cin >> p[i].x >> p[i].y;
	}

	int64 pontos = 0;
	for (int64 i = 0; i < t; i++) {
		double r = hypot(p[i].x, p[i].y);
		int64 x = (lower_bound(raios, raios+c, r)) - raios;
		if (raios[x] >= r)
			pontos += PONTOS[x];
	}

	cout << pontos << endl;
	return 0;
}
