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
const int T = 1e5;
int proc[N];

int main() {
	ios::sync_with_stdio(false);
	int n, k, t;

	memset(proc, 0, sizeof(proc));

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> t;
		proc[t]++;
	}

	size_t maxcont = 0;
	queue<int> rqs;
	for (int i = 0; i <= T; i++) {
		while (!rqs.empty() && i - rqs.front() >= 1000)
			rqs.pop();

		if (proc[i] > 0) {
			for (int j = 0; j < proc[i]; j++)
				rqs.push(i);
		}

		maxcont = max(maxcont, rqs.size());
	}

	int ans = maxcont / k;
	ans += (maxcont % k) ? 1 : 0;

	cout << ans << endl;
	return 0;
}
