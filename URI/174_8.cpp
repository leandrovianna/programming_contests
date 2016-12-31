#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double l;
	int qtd;

	cin >> l;
	qtd = 0;
	while (l >= 2) {
		l /= 2;
		qtd++;
	}

	cout << (int) pow(4, qtd) << endl;
	return 0;
}
