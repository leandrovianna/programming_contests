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

typedef struct {
	string f, l;
} person;

int main() {
	ios::sync_with_stdio(false);
	const int N = 1000;
	person ps[N];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ps[i].f >> ps[i].l;
	}

	sort(ps, ps+n, [](person a, person b) {
			return (a.l == b.l && a.f < b.f)
				|| (a.l < b.l);
			});

	for (int i = 0; i < n; i++)
		cout << ps[i].f << " " << ps[i].l << endl;
	return 0;
}
