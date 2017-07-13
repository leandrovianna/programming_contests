// WA
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

const int N = 1010;

typedef struct {
	int d, a, b;
} Wall;

int main() {
	int n;
	Wall w[N];
	int dt, at, bt;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i].d >> w[i].a >> w[i].b;
	}

	cin >> dt >> at >> bt;


	double tetaAt = 0, tetaBt = 1e10;
	for (int i = 0; i < n; i++) {
		tetaAt = max(tetaAt, atan2(w[i].a, w[i].d));
		tetaBt = min(tetaBt, atan2(w[i].b, w[i].d));
	}

	double maxTetaAt = atan2(bt, dt);
	double minTetaBt = atan2(at, dt);
	
	if (tetaAt >= tetaBt) 
		cout << "N" << endl;
	else if (tetaAt > maxTetaAt)
		cout << "N" << endl;
	else if (tetaBt < minTetaBt)
		cout << "N" << endl;
	else
		cout << "Y" << endl;

	return 0;
}
