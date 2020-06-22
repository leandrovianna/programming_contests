//Despojados - Maratona Regional 2017
#include <iostream>
#include <iomanip>
#include <bitset>
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
	
	i64 n, f;
	cin >> n;

	int j = 0;
	f = 2;

	while (f * f <= n) {
		if (n % f == 0) {
			j++;
			while (n % f == 0) n /= f;
		}
		f++;
	}

	if (n > 1) j++;

	// number of 'despojados' is 2^j - (j+1),
	// where j is number of distinct prime factors

	cout << (1LL << j) - j - 1 << endl;

	return 0;
}
