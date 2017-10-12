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

const int M = 2*1e6+10;
bool ex[M];

int main() {
	ios::sync_with_stdio(false);
	const int N = 2100;
	int n;
	int x[N], y[N];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		ex[x[i]] = true;
	}

	for (int i = 0; i < n; i++) {
		cin >> y[i];
		ex[y[i]] = true;
	}

	int cont = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int k = x[i] ^ y[j];

			if (k < M) cont += ex[k];
		}
	}

	// cout << cont << endl;
	cout << (cont % 2 == 0 ? "Karen" : "Koyomi") << endl;
	return 0;
}
