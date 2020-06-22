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
	int t1[3], t2[3];

	for (int i = 0; i < 3; i++)
		cin >> t1[i];

	for (int i = 0; i < 3; i++)
		cin >> t2[i];

	sort(t1, t1+3);
	sort(t2, t2+3);

	bool r = true;
	for (int i = 0; i < 3; i++)
		if (t1[i] != t2[i]) {
			r = false;
			break;
		}

	int d = t1[0] * t1[0] + t1[1] * t1[1];
	if (r && d == (t1[2] * t1[2]))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
