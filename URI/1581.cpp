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
	int n, k;
	string s, r; 
	bool res;

	cin >> n >> r;
	n--;
	while (n--) {
		cin >> s;

		if (r != s) res = false;

		r = s;
	}
	return 0;
}
