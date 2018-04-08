//CodeChef - Total Diamonds - DEC17 VK18
#include <bits/stdc++.h>
using namespace std;

int value(int x) {
	int d, a = 0, b = 0;
	while (x > 0) {
		d = x % 10;	
		if (d % 2 == 0) a += d;
		else b += d;

		x /= 10;
	}
	return abs(a - b);
}

const int N = 1'000'010;
int cache[2*N];
int64_t sum[N];
int64_t pre[2*N];

int main() {
	ios::sync_with_stdio(false);
	int t, n;

	for (int i = 1; i < 2*N; i++) {
		cache[i] = value(i);
	}

	pre[2] = cache[2];
	for (int i = 3; i < 2*N; i++) {
		pre[i] = pre[i-1] + cache[i];
	}

	sum[1] = 2;
	for (int i = 2; i < N; i++) {
		sum[i] = sum[i-1] + 2 * (pre[2*i-1] - pre[i]) + cache[2*i];
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << sum[n] << endl;
	}

	return 0;
}
