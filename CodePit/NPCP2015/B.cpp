#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

template<typename T>
void print_vector(vector<T> v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it;
		if (next(it) != v.end())
			cout << " ";
	}
	cout << endl;
}

const int N = 10;
vector<vector<int> > rows[N];

void calculate(int n) {
	if (n == 1) {
		rows[n] = { {1} };
	}
	else {
		calculate(n-1);

		bool flag = true;
		for (auto v : rows[n-1]) {

			if (flag) {
				v.push_back(n);

				for (int i = n-1; i >= 0; i--) {
					rows[n].push_back(v);
					swap(v[max(0, i-1)], v[i]);
				}
			}
			else {
				v.emplace(v.begin(), n);

				for (int i = 0; i < n; i++) {
					rows[n].push_back(v);
					swap(v[i], v[min(n-1, i+1)]);
				}
			}

			flag = !flag;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	vector<int> v;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	
	calculate(n);

	for (auto &u : rows[n]) {
		print_vector(u);
	}

	return 0;
}
