#include <iostream>
#include <vector>
using namespace std;

int main() {
	const int N = 1e5;
	vector<int> graph[N];	
	int n, m, a, b;

	cin >> n >> m >> a >> b;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int qtd = n;
	for (int i = 0; i < n; i++) {
		int s = graph[i].size();
		if (s < a && qtd - s < b) {
			qtd--;
			for (int j = 0; j < s; j++) {
				int x = graph[i][j];
			}
		}
	}

	cout << qtd << endl;
	return 0;
}
