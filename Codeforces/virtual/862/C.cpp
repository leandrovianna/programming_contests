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
	int x, n;		
	int64_t acc;

	cin >> n >> x;
	
	if (n == 2 && x == 0)
		cout << "NO\n";
	else if (n == 1)
		cout << "YES\n" << x << "\n";
	else if (n == 2)
		cout << "YES\n" << 0 << " " << x << "\n";
	else {
		cout << "YES\n";
		acc = 0;
		for (int i = 1; i <= n-3; i++) {
			cout << i << " ";
			acc = acc ^ i;
		}

		if (x == acc) {
			cout << (1<<17) << " " << (1<<18) << " "
				<< ((1<<17) ^ (1<<18)) << "\n";
		} else {
			cout << 0 << " " << (1<<17) << " "
				<< ((1<<17) ^ acc ^ x) << "\n";
		}
	}

	return 0;
}
