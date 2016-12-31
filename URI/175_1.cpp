#include <iostream>
using namespace std;

int mdc(int a, int b) {
	return (b == 0) ? a : mdc(b, a % b);
}

int mdc(int a, int b, int c) {
	return mdc(a, mdc(b, c));
}

int main() {
	const int N = 4;
	int a[N], m1, m2, at = 0;
	string res;
	const int P[][N] = {
		{0, 1, 2, 3},
		{1, 0, 2, 3},
		{1, 2, 0, 3},
		{1, 2, 3, 0},
		{2, 1, 3, 0},

	const int J[] = {1, 2, 3,

	for (int i = 0; i < N; i++) {
		cin >> a[i];
		at += a[i];
	}

	res = "N";

	for (int k = 0; k < 24; k++) {
			int i = I[k];
			int j = J[k];

			m1 = mdc(a[i] + a[i+1], at);
			m2 = mdc(a[j] + a[j+1], at);

			if (m1 * m2 == at) {
				res = "S";
				break;
			}

		}	
	}


	cout << res << endl;
	return 0;
}
