//URI - Vila Natalina - I
#include <bits/stdc++.h>
using namespace std;

template <typename T>
T gcd(T a, T b) {
	return b == 0 ? a : gcd(b, a % b);
}

const int N = 1010;
const int M = N*N;
int mm = 0; // qtd de arestas
pair<int64_t, pair<int, int> > edges[M];

void add_edge(int to, int from, int64_t weight) {
	edges[mm].first = weight;
	edges[mm].second.first = to;
	edges[mm].second.second = from;
	mm++;
}

namespace UF {
	int parent[N];
	void init(int sz) {
		for (int i = 0; i < sz; i++)
			parent[i] = i;
	}
	int find(int x) {
		if (parent[x] == x) return x;
		else return parent[x] = find(parent[x]);
	}
	void join(int x, int y) {
		x = find(x);
		y = find(y);

		if (x != y)
			parent[x] = y;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t, n;
	int64_t k, answer;
	pair<int, int> points[N];

	cin >> t;
	while (t--) {
		mm = 0; // limpando as arestas

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> points[i].first;
			cin >> points[i].second;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;

				int64_t a = abs(points[i].first - points[j].first);
				int64_t b = abs(points[i].second - points[j].second);
				int64_t w = k * (__gcd(a, b) - 1LL);
				add_edge(i, j, w);
			}
		}

		sort(edges, edges+mm);

		UF::init(n);

		answer = 0;
		for (int i = 0; i < mm; i++) {
			int u = edges[i].second.first;
			int v = edges[i].second.second;
			if (UF::find(u) != UF::find(v)) {
				UF::join(u, v);
				answer += edges[i].first;
			}
		}

		cout << answer << endl;
	}

	return 0;
}
