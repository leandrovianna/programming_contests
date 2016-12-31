//https://www.urionlinejudge.com.br/judge/pt/problems/view/1547
#include <iostream>
#include <cmath>
using namespace std;

const int INF = 10000000;

int ganhador(const int[], const int, const int);

int main() {
	const int QT = 10;
	int n, qt, s, a[QT];

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> qt >> s;
		for (int j = 0; j < qt; ++j) {
			cin >> a[j];
		}

		cout << ganhador(a, qt, s) << endl;
	}
	return 0;
}

int ganhador(const int a[], const int N, const int s) {
	int diff = INF, i_diff, diff_tmp;
	for (int i = 0; i < N; ++i) {
		if (a[i] == s)
			return i+1;

		diff_tmp = abs(s - a[i]);
		if (diff_tmp < diff) {
			diff = diff_tmp;
			i_diff = i;
		}
	}

	return i_diff+1; 
}
