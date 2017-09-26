#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

const int N = 1e5+10;
int n, k, r, v[N];

int main() {
	ios::sync_with_stdio(false);
	int x;

	cin >> n >> k >> r;
	for (int i = 0; i < k; i++) {
		cin >> x;
		v[x-1] = 1;
	}

	stack<int> pilha;
	int e = 0, d = r-1, sum = 0;

	for (int i = e; i <= d; i++) {
		sum += v[i];
		if (v[i] == 0)
			pilha.push(i);
	}

	int k = 0;
	while (d < n) {
		// cout << e << " " << d << " " << sum << endl;
		while (sum < 2 && !pilha.empty()) {
			int i = pilha.top();
			pilha.pop();
			v[i] = 1;
			k++;
			sum++;
		}

		sum -= v[e]; // retira camera (se existir da casa anterior)
		e++; // sobe os ponteiros
		d++;

		// se nova casa d tem camera ou nao
		if (v[d] == 0) pilha.push(d);
		else sum++;
	}

	cout << k << endl;
	return 0;
}
