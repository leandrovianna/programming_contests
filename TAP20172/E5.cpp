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

const int NOTAS = 12;
int v[NOTAS], cont[NOTAS];

int main() {
	ios::sync_with_stdio(false);
	int n, x;
	const int T = 7;
	const int notas[] = {2, 2, 1, 2, 2, 2, 1};
	const string tom[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#",
		"sol", "sol#", "la", "la#", "si"};

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		x--;
		v[x%NOTAS]++;
	}

	for (int i = 0; i < NOTAS; i++) {
		cont[i] = 0;
		x = i; // primeira nota do tom

		for (int j = 0; j < T; j++) {
			x += notas[j];
			x %= NOTAS;
			// se nota esta presente
			if (v[x]) cont[i] += v[x]; // mais uma para esse tom
		}
	}

	for (int i = 0; i < NOTAS; i++) {
		// cout << cont[i] << " " << tom[i] << endl;
		if (cont[i] == n) {
			cout << tom[i] << endl;
			return 0;
		}
	}

	cout << "desafinado\n";
	return 0;
}
