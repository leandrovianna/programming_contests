#include <iostream>
#include <cstdio>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

int main() {
	int n, m, p;
	map<string, double> prod;
	map<string, int> compra;
	string nome;
	double total = 0, valor;
	int qtd;

	cin >> n;
	for (int i = 0; i < n; i++) {
		total = 0;

		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> nome;
			cin >> valor;
			prod[nome] = valor;
		}

		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> nome;
			cin >> qtd;
			compra[nome] = qtd;
		}

		for (map<string,int>::iterator it = compra.begin(); 
				it != compra.end(); it++){
			total += prod[(*it).first] * (*it).second;
		}

		// cout << "R$ " << setprecision(4) << total << endl;
		printf("R$ %.2lf\n", total);
		compra.clear();
	}
	return 0;
}
