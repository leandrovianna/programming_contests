#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

#define N 100100 //10^5

int main() {
	i64 n, p, d[N];	

	i64 diff = 0, ideal;

	cin >> n >> p;
	for (int i = 0; i < n; i++)
		cin >> d[i];

	sort(d, d+n);

	for (int i = 0; i < n; i++) {
		ideal = p * (i + 1);
#ifdef DEBUG
		cout << "i : " << i << " d[i]: " << d[i] << endl;
		cout << "diff : " << diff << " ideal: " << ideal << endl;
#endif

		if (d[i] + diff < ideal) {
			diff += ideal - (d[i] + diff);
		}
	}

	cout << d[0] + diff << endl;
	return 0;
}
