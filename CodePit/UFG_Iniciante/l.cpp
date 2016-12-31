//https://www.urionlinejudge.com.br/judge/pt/problems/view/1089
#include <iostream>
using namespace std;

int picos(const int[], const int);

int main() {
	const int N = 10000;
	int n, v[N];

	while (cin >> n && n != 0) {

		for (int i = 0;  i < n; ++i) {
			cin >> v[i];
		}

		cout << picos(v, n) << endl;
	}

	return 0;
}

int picos(const int v[], const int n) {
	int picos = 0, left, right;
	for (int i = 0; i < n; ++i) {
		left = i < 1 ? (i - 1) + n : i - 1;
		right = i > n-2 ? (i + 1) - n : i + 1;

		if (v[left] < v[i] && v[right] < v[i])
			picos++;
		else if (v[left] > v[i] && v[right] > v[i])
			picos++;
	}
	return picos;
}
