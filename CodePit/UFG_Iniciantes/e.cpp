#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	const int N = 5 * 100000;
	int v[N], n, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v, v+n);
	//calculando mediana
	m = n / 2;
	if (n % 2 == 0)
		m--; //pegar o mais esquerda em caso de duas medianas
	cout << v[m] << endl;

	return 0;
}
