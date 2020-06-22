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

int main() {
	ios::sync_with_stdio(false);
	const int N = 1e5;
	int n, k, v[N];

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v, v+n);

	for (int i = n-k-1; i >= 0; i--) {
		if (v[i] == v[i+1]) k++;
		else break;
	}

	cout << k << endl;
	return 0;
}
