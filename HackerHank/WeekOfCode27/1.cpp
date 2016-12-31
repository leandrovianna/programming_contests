#include <iostream>
using namespace std;

int main() {
	int n, p;	

	cin >> n >> p;

	int qtd1 = (int) p / 2;
	int qtd2;
	if (n % 2)
		qtd2 = (n - p) / 2; 
	else
		qtd2 = (n - p + 1) / 2;

	cout << ((qtd1 < qtd2) ? qtd1 : qtd2) << endl;
	return 0;
}
