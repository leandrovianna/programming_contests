//MCOINS - Spoj
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

const int N = 1e6+10;
int K, L;
bool win[N];

int main() {
	ios::sync_with_stdio(false);
	int n, m;

	cin >> K >> L >> m;
	win[0] = false;
	win[K] = win[L] = win[1] = true;

	while (m--) {
		cin >> n;

		for (int i = 2; i <= n; i++) {
			win[i] = false;
			if (!win[i-1]) win[i] = true;
			if (i >= K && !win[i-K]) win[i] = true;
			if (i >= L && !win[i-L]) win[i] = true;
		}

		cout << (win[n] ? "A" : "B");
	}
	cout << endl;
	return 0;
}
