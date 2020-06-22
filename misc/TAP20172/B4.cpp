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

const int J = 510;
int pontos[J];

int main() {
	ios::sync_with_stdio(false);
	int j, r, p, resp;

	cin >> j >> r;
	for (int k = 0; k < r; k++) {
		for (int i = 0; i < j; i++) {
			cin >> p;
			pontos[i] += p;
		}
	}

	int m = 0;

	for (int i = 0; i < j; i++) {
		if (pontos[i] >= m) {
			resp = i+1;
			m = pontos[i];
		}
	}

	cout << resp << endl;
	return 0;
}
