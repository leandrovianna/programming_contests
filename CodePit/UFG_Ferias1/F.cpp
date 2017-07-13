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

const int N = 1e5;

int pai[N], peso[N];

int find(int x) {
	if (pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);

	if (peso[x] < peso[y]) {
		pai[x] = y;
	} else if (peso[x] > peso[y]) {
		pai[y] = x;
	} else {
		pai[x] = y;
		peso[y]++;
	}
}

int main() {
	int n, m;
	int a, b;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		pai[i] = i;
		peso[i] = 0;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		join(a, b);
	}

	int qtd = 0;
	for (int i = 0; i < n; i++) {
		if (pai[i] == i) qtd++;
	}

	cout << qtd << endl;
	return 0;
}
