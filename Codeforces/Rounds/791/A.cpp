#include <iostream>
using namespace std;

int main() {
	int a, b, qtd = 0;

	cin >> a >> b;

	while (a <= b) {
		qtd++;
		a *= 3;
		b *= 2;
	}

	cout << qtd << endl;
	return 0;
}
