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

const int N = 1e6+10;
const int S = 4001;
int n, cont[N], x;
int sum[S];

int main() {
	ios::sync_with_stdio(false);

	memset(cont, 0, sizeof(cont));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cont[x]++;
	}

	for (int i = 1; i <= 2000; i++)
		for (int j = i; j <= 2000; j++)
			sum[i+j] += (i == j) ? cont[i]/2 : min(cont[i], cont[j]);

	int l = 0, c = 0;
	for (int i = 2; i < S; i++) {
		if (sum[i] > l) l = sum[i], c = 1;
		else if (sum[i] == l) l = sum[i], c++;
	}

	cout << l << " " << c << endl;

	return 0;
}
