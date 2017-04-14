#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

typedef unsigned long int uint64;

void which_way(uint64 n) {
	string bin = bitset<64>(n).to_string();
	int qtd1, qtd0;
	bool count = false;

	// cout << n << " " << bin << endl;
	
	if (n == 0)
		qtd0 = 1;
	else {

		qtd1 = qtd0 = 0;

		for (size_t i = 0; i < bin.size(); i++) {
			if (bin[i] == '1') {
				count = true;
				qtd1++;
			}

			if (count && bin[i] == '0')
				qtd0++;
		}
	}

	if (qtd0 > qtd1)
		cout << "left" << endl;
	else if (qtd1 > qtd0)
		cout << "right" << endl;
	else
		cout << "straight" << endl;
}

int main() {
	uint64 x;

	while (cin >> x) {
		which_way(x);
	}
	return 0;
}
