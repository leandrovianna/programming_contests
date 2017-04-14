//TLE
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

#define C 10000
#define E 10000

int main() {
	int t, n, c, e, qtd, p, x, y;
	set<int> cameras;
	int estrelas[E];

	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		cin >> n >> c;
		for (int i = 0; i < c; i++) {
			scanf("%d %d", &x, &y);
			for (int k = x; k <= y; k++)
				cameras.insert(k);
		}
		
		cin >> e;
		qtd = 0;
		for (int i = 0; i < e; i++) {
			scanf("%d", &p);
			if (cameras.find(p) != cameras.end())
				qtd++;
		}

		cout << "Caso #" << ti+1 << ": " << qtd << endl;
	}	
	return 0;
}
