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

const int N = 101000;

int main() {
	ios::sync_with_stdio(false);
	int64_t v[N];	
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int64_t p = 0; // let p be the number of mismatched pairs
	int64_t x, y; // two largests in heap

	make_heap(v, v+n);

	while (n > 1) {
		pop_heap(v, v+n); // move largest to end
		x = v[n-1]; // get the largest
		n = n - 1; // reduce the size of heap
		pop_heap(v, v+n); // move second largest to end
		y = v[n-1]; // get the second largest

		p += y; // increase the number of pair
		v[n-1] = x - y; // insert in heap the rest of pairs
		push_heap(v, v+n); // make heap again
	}

	cout << p << endl;

	return 0;
}
