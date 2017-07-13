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

const int N = 110;

int main() {
	int n, v[N];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> sum, prod, left;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			sum.push_back(v[i] + v[j]);
			prod.push_back(v[i] * v[j]);
		}

	for (int i = 0; i < n*n; i++) {
		for (int j = 0; j < n; j++) {
			left.push_back(prod[i] + v[j]);
		}
	}

	int qtd = 0;
	sort(left.begin(), left.end());
	for (int i = 0; i < n*n; i++) {
		for (int j = 0; j < n; j++) {
			int d = v[j];
			if (d != 0) {
				int num = sum[i] * d;

				auto low = lower_bound(left.begin(), left.end(), num);
				auto upper = upper_bound(left.begin(), left.end(),num);

				qtd += upper - low;
			}
		}
	}

	cout << qtd << endl;
	return 0;
}
