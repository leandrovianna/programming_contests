#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int x, y;
} consulta;

bool compara(consulta a, consulta b) {
	return (a.y <= b.y);
}

int main() {
	const int N = 10000;
	int n;
	consulta c[N];

	cin >> n;
	for (int ni = 0; ni < n; ni++) {
		cin >> c[ni].x >> c[ni].y;
	}
	
	sort(c, c+n, compara);
	
	int fim = c[0].y;
	int qtd = 1;
	for (int i = 1; i < n; i++) {
		if (c[i].x >= fim) {
			fim = c[i].y;
			qtd++;
		}
	}

	cout << qtd << endl;

	return 0;
}
