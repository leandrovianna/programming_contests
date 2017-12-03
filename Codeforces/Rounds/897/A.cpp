//Codeforces - Scarborough Fair - 897A
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	int l, r;
	char c1, c2;
	char s[1000];

	cin >> n >> m;
	cin >> s;

	for (int i = 0; i < m; i++) {
		cin >> l >> r >> c1 >> c2;
		l--;
		r--;
		for (int k = l; k <= r; k++)
			if (s[k] == c1)
				s[k] = c2;
	}

	cout << s << endl;
	
	return 0;
}
