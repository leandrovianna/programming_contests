//After contests
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef long i32;
typedef long long i64;

#define N ((i32)1e9)

int main() {
	i32 t, x, y, p, q;
	i64 a, b, res, ini, fim, mid;

	cin >> t;
	while (t-- > 0) {
		cin >> x >> y >> p >> q;

		res = -1;
		ini = 0, fim = N, mid;
		while (ini <= fim) {
			mid = (ini+fim)/2;
			a = p * mid - x;
			b = q * mid - y;
	
			if (a >= 0 && b >= 0 && a <= b) {
				res = b;
				fim = mid-1;
			} else {
				ini = mid+1;
			}
		}

		cout << res << endl;
	}
	return 0;
}
