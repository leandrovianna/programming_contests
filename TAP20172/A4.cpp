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
	int n, q;
	int fat = 1, i;
	cin >> n;

	while (n > 0) {
		i = 1;
		fat = 1;

		while (fat <= n) {
			fat = fat * i;
			i++;
		}

		// cout << n << " " << fat << " " << i << endl;
		n -= fat / (i-1);
		q++;
	}

	cout << q << endl;

	return 0;
}
