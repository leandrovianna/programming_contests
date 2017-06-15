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

template<typename T, typename F>
void mergeSort(vector<T> &v, F compare) {
	if (v.size() == 1) return;

	vector<T> u1, u2;
	for (size_t i = 0; i < v.size()/2; i++)
		u1.push_back(v[i]);

	for (size_t i = v.size()/2; i < v.size(); i++)
		u2.push_back(v[i]);

	mergeSort(u1, compare);
	mergeSort(u2, compare);

	int j = 0, k = 0;
	for (size_t i = 0; i < v.size(); i++) {
		if (j >= u1.size()) {
			v[i] = u2[k];
			k++;
		}
		else if (k >= u2.size()) {
			v[i] = u1[j];
			j++;
		}
		else if (compare(u1[j], u2[k])) {
			v[i] = u1[j];
			j++;
		} else {
			v[i] = u2[k];
			k++;
		}
	}
}

bool f(int x, int y) {
	return (x > y);
}

int main() {
	size_t n;
	vector<int> v;
	int x;

	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	mergeSort(v, f);

	for (size_t i = 0; i < n; i++) {
		cout << v[i];
		if (i != n-1) cout << " ";
	}
		
	return 0;
}
