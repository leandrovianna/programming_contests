//Judge - Problem Name - Problem ID
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	int k = n-1;
	int y = min(a, min(b, c));
	int ans = 0;

	if (k == 0)
		ans = 0;
	else if (a == y)
		ans = a * k;
	else if (b == y)
		ans = b * k;
	else if (c == y) {
		ans = min(a,b) + c * (k-1);
	}

	cout << ans << endl;
	return 0;
}
