#include <iostream>
using namespace std;

#define N 100000

int main() {
	int v[N];
	int n, m;

	m = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int i = 0;
	while (i < n) {
		i += v[i] + 1;
		m++;
	}

	cout << m << endl;
	return 0;
}
