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

const int X = 110;
int ind[X];

int main() {
	ios::sync_with_stdio(false);
	int n, x, z;

	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> z;
		ind[z] = 1;
	}

	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		if (ind[i] == 1 && i == x) {
			ans++;
			break;
		}

		if (ind[i] == 0) {
			if (i == x) break;

			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
