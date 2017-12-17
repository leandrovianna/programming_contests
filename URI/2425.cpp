//URI - Banco - 2425
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int c, n;
	cin >> c >> n;

	vector<pair<int, int> > clientes(n);

	for (auto &c : clientes) {
		cin >> c.first >> c.second;
	}

	priority_queue<int, vector<int>, greater<int> > caixas;

	for (int i = 0; i < c; i++) {
		caixas.push(0);
	}

	int answer = 0;

	for (const auto &cliente : clientes) {
		int c = caixas.top();
		caixas.pop();

		// cout << cliente.first << " atendido em " << c << endl;
		if (c - cliente.first > 20)
			answer++;

		caixas.push( max(cliente.first, c) + cliente.second );
	}

	cout << answer << endl;
	return 0;
}
