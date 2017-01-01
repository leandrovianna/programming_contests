//Algoritmos Gulosos
//51 - Bolsas
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 100000

typedef struct {
	int t, d;
} enc;

bool compara(enc a, enc b) {
	if (a.d == b.d) {
		return (a.t < b.t);
	} else return (a.d < b.d);
}

int main() {
	int n;
	long s, atr;
	enc e[MAXN];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> e[i].t >> e[i].d;
	}

	sort(e, e+n, compara);

	// for (int i = 0; i < n; i++) {
	// 	cout << e[i].t << ' ' << e[i].d << endl;
	// }

	atr = 0;
	s = 0;
	for (int i = 0; i < n; i++) {
		atr = max(atr, s + e[i].t - e[i].d);
		s += e[i].t;
	}

	cout << atr << endl;
	return 0;
}
