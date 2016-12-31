#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int t, d;
} encomenda;

bool compara(encomenda a, encomenda b) {
	return (a.d < b.d);
}

int maxi(int a, int b) {
	return (a >= b) ? a : b;
}

int main() {
	const int N = 10000;
	int n;
	long long s, atr;
	encomenda v[N];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i].t;
		cin >> v[i].d;
	}

	atr = 0;
	s = 0;
	sort (v, v+n, compara);
	for (int i = 0; i < n; i++) {
		atr += maxi(0, s + v[i].t - v[i].d);
		s += v[i].t;
	}

	cout << atr << endl;
	return 0;
}
