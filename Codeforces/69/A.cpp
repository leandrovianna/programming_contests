#include <iostream>
using namespace std;

int main() {
	int x = 0, y = 0, z = 0, n, k, l, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k >> l >> m;
		x += k;
		y += l;
		z += m;
	}

	if (!(x || y || z))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
