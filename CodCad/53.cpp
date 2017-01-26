//Accepted - 100 points
#include <iostream>
using namespace std;

#define N 100000

typedef pair<int, int> ii;

ii bs(const int v[], const int n, const int k) {
	int ini = 0, fim = n-1, meio;

	while (ini < fim) {
		int x = v[ini] + v[fim];
		if (x == k)
			return make_pair(v[ini], v[fim]);
		else if (x > k)
			fim = fim-1;
		else if (x < k)
			ini = ini+1;
	}

	return make_pair(-1, -1);
}

int main() {
	int n, c[N], k;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];

	cin >> k;

	ii p = bs(c, n, k);

	cout << p.first << " " << p.second << endl;
	return 0;
}
