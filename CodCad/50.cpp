#include <iostream>
using namespace std;

int main() {
	int n, qtd;
	int moedas[6] = {100, 50, 25, 10, 5, 1};

	cin >> n;

	qtd = 0;
	while (n) {
		for (int i = 0; i < 6; i++) {
			if (n >= moedas[i]) {
				n -= moedas[i];
				break;
			}
		}
		qtd++;
	}

	cout << qtd << endl;
	return 0;
}
