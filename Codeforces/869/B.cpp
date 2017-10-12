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
	int64_t a, b;	

	cin >> a >> b;
	
	int64_t d = b - a;

	if (d >= 10) cout << 0 << endl;
	else {
		int64_t f = 1;
		for (int64_t i = a+1; i <= b; i++)
			f = (f * i) % 10;

		cout << f % 10 << endl;
	}

	return 0;
}
