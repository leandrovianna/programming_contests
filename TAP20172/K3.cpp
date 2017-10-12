#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	vector<int> p1(6), p2(6);

	for (int i = 0; i < 6; i++)
		cin >> p1[i];
	for (int i = 0; i < 6; i++)
		cin >> p2[i];

	int qtd = 0, emp = 0;

	for (auto &d1 : p1) {
		for (auto &d2 : p2) {
			if (d1 > d2) qtd++;
			else if (d1 == d2) emp++;
		}
	}

	double res = qtd / (36.0 - emp);
	cout << fixed << setprecision(5) << res << endl;
	return 0;
}
