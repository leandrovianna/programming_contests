#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define N 100000 // 10^5
#define MOD (1000000000 + 7)

typedef vector<int> vii;

vii g[N];
int comp[N];

int bfs(int v, int n) {
	int fila[N], tam = 0, x;
	fila[tam++] = v;
	comp[v] = 1;

	memset(comp, -1, sizeof(comp));

	int qtd = 1;

	while (tam > 0) {
		x = fila[tam-1];
		tam--;
		for (const int &u : g[x]) {
			if (comp[u] == -1 && g[u].size() > 0) {
				qtd *= 2;
				qtd %= MOD;
				fila[tam++] = u;
				comp[u] = comp[x];
			}
		}
	}

	return qtd + 2;
}

int main() {
	int n, a, b, h[N];

	cin >> n;
	memset(h, 0, n * sizeof(int));
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		a--;
		b--;
		h[b] = 1;
		g[a].push_back(b);
		// g[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
		if (h[i] == 0) {
			a = i;
			break;
		}

	cout << bfs(a, n) << endl;
	return 0;
}
