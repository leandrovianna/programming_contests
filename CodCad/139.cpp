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

const int max_sum(const int v[], const int n) {
	int maior = 0, resp = 0;

	for (int _ = 0; _ < 2; _++) {
		for (int i = 0; i < n; i++) {
			maior = max(0, maior + v[i]);
			resp = max(resp, maior);
		}
	}

	return resp;
}

int main() {
	const int N = 1e6;
	int n, v[N];	

	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	cout << max_sum(v, n) << endl;
	return 0;
}
