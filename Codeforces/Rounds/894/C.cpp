//Codeforces - Marco and GCD Sequence - 894C
#include <bits/stdc++.h>
using namespace std;

const int M = 1'000'010;

int main() {
	ios::sync_with_stdio(false);
	const int N = 1010;
	int n, s[N];
	// set<int> st;
	array<bool, M> ind;
	ind.fill(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		ind[s[i]] = true;
		// st.insert(s[i]);
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = i; j < n; j++) {
	// 		// int x = s[i];
	// 		// for (int k = i+1; k <= j; k++)
	// 		// 	x = __gcd(x, s[k]);
	// 		int x = __gcd(s[i], s[j]);
    //
	// 		if (!ind[x]) {
	// 			cout << -1 << endl;
	// 			return 0;
	// 		}
	// 	}
	// }
	
	for (int i = 1; i < n; i++) {
		if (s[i] % s[0]) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << 2*n+1 << endl;
	cout << s[0] << " ";
	for (int i = 0; i < n; i++)
		cout << s[i] << " " << s[0] << " \n"[i == n-1];

	return 0;
}
