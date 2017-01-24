//After Contests - Accepted
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long a[3];
	cin >> a[0] >> a[1] >> a[2];

	long long m = max(a[0], max(a[1], a[2]));
	long long r = 0;

	for (int i = 0; i < 3; i++) {
		if (m == a[i]) continue;
		else r += max(0LL, (m-1) - a[i]);
	}

	cout << r << endl;
	return 0;
}
