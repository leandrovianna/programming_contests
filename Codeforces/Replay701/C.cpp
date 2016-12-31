#include <iostream>
#include <map>
using namespace std;

int main() {
	const int N = 1e5;
	const int INF = 9*1e5;
	int n, t;
	char f[N];	
	map<char, int> cat;

	t = 0; //qtd of types

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
		if (cat.find(f[i]) == cat.end()) {
			cat[f[i]] = i;
			t++;
		}
	}

	int minimo = INF;
	for (int i = 0; i <= n-t; i++) {
		cat[f[i]] = i;

		int j = i;
		for (auto it = cat.begin();
				it != cat.end(); it++) {
			if (it->second < i) {
				j = i - 1;
				break;
			}
			j = max(j, it->second);
		}
		
		int d = j - i + 1;
		if (d >= t)
			minimo = min(minimo, d);
	}

	cout << minimo << endl;
	return 0;
}
