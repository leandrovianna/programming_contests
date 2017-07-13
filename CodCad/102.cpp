#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int N = 110;

int main() {
	int a, v, x, y;
	int cont[N];
	int r[N], k;
	int m, cs;

	cs = 1;
	while (cin >> a >> v, a || v) {
		memset(cont, 0, sizeof(cont));

		for (int i = 0; i < v; i++)	{
			cin >> x >> y;
			cont[x]++;
			cont[y]++;
		}

		m = 0;
		for (size_t i = 1; i <= a; i++) {
			m = max(m, cont[i]);
		}

		k = 0;
		for (size_t i = 1; i <= a; i++) {
			if (cont[i] == m) r[k++] = i;
		}

		cout << "Teste " << cs << endl;
		for (size_t i = 0; i < k; i++) {
			cout << r[i];
			if (i != k-1) cout << " ";
		}
		cout << endl << endl;

		cs++;
	}
	return 0;
}
