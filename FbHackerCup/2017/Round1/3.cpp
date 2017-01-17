#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

const int N = 100;

vii family;
vii g[N];


int main() {
	int t, n, m, k, a, b, s, d, p;
	
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		cin >> n >> m >> k;
		for (int mi = 0; mi < m; mi++) {
			cin >> a >> b >> p;
			a--; b--;
			g[a].push_back(make_pair(b, p));
			g[b].push_back(make_pair(a, p));
		}
		for (int ki = 0; ki < k; ki++) {
			cin >> s >> d;
			family.push_back(make_pair(s, d));
		}
	}
	return 0;
}
