#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	const int N = 1e5;
	int n, p, a[N];	
	bool qtd[N];

	memset(qtd, false, N);

	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long amount = 0;
	for (int i = 0; i < n; i++) {
		int x = ceil((double) a[i] / p);

		while (qtd[x]) {
			x++;
		}

		amount += x;
		qtd[x] = true;
		cout << x << endl;
	}

	cout << amount << endl;
	return 0;
}
