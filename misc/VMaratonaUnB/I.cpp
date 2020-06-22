#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	double d, n[7];
	
	cin >> t;
	cout << fixed << setprecision(1);
	for (int ti = 1; ti <= t; ti++) {
		cin >> d;
		for (int i = 0; i < 7; i++)
			cin >> n[i];
		sort(n, n+7);
		double sum = 0;
		for (int i = 1; i < 6; i++)
			sum += n[i];
		double ans = (sum / 5) * d;
		cout << "Caso " << ti << ": " << ans << "\n";
	}

	return 0;
}
