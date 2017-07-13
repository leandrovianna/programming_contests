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

int main() {
	const int N = 10000;
	int qtd[N], x, n, m, winner;

	memset(qtd, 0, sizeof(qtd));

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		qtd[x]++;
	}

	m = 0;
	for (int i = 0; i < N; i++) {
		if (qtd[i] > m) {
			m = qtd[i];
			winner = i;
		}
	}

	cout << winner << endl;

	return 0;
}
