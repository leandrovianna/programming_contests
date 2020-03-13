#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, qtd;
	string s;
	map<string, int> m;

	cin >> n;
	// recebendo linha em branco
	cin.get();
	cin.get();

	for (int i = 0; i < n; i++) {
		qtd = 0;
		m.clear();

		getline (cin, s);

		while (s.size() > 0) {
			if (m.find(s) != m.end())
				m[s]++;
			else
				m[s] = 1;

			qtd++;
			getline(cin, s); // recebendo proximo nome arvore
		}

		for (map<string, int>::iterator it = m.begin(); 
				it != m.end(); ++it) {
			cout << it->first << " "
				<< fixed << setprecision(4) << 
					((float) it->second / qtd) * 100.0 << endl;
		}
		if (i != n-1) // se nao for o ultimo conj
			cout << endl; // linha em branco separando conj de dados
	}
	return 0;
}
