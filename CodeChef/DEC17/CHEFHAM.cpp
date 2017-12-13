//CodeChef - Chef and Hamming Distance of arrays - DEC17 CHEFHAM
#include <bits/stdc++.h>
using namespace std;

template<typename T>
int hamming(T a[], T b[], size_t n) {
	int qtd = 0;
	for (size_t i = 0; i < n; i++) {
		if (a[i] != b[i]) qtd++;
	}
	return qtd;
}

const int N = 100'110;

int main() {
	ios::sync_with_stdio(false);
	int t, n, v1[N], v2[N];

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> v1[i];
			v2[(i+2) % n] = v1[i];
		}

		for (int i = 0; i < n; i++) {
			if (v1[i] == v2[i]) {
				if (i < n-1 && v2[i] != v2[i+1]) {
					swap(v2[i], v2[i+1]);
				}
				else if (i > 0 && v2[i] != v2[i-1]) {
					swap(v2[i], v2[i-1]);
				}
			}
		}

		int ans = hamming(v1, v2, n);
		cout << ans << endl;
		for (int i = 0; i < n; i++) {
			cout << v2[i] << " \n"[i == n-1];
		}
	}
	return 0;
}
