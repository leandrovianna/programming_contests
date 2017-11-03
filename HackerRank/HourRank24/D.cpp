//HackerRank - Kth Minimum
#include <bits/stdc++.h>
using namespace std;

const int N = 2*1e5+10;

int bit[N];

// execute the query [1, x]
int query(int x) {
	int s = 0;
	
	while (x) {
		s += bit[x];
		x -= (x & -x);
	}

	return s;
}

// execute the update [1,x]
void update(int x, int v) {
	while (x <= N) {
		bit[x] += v;
		x += (x & -x);
	}
}

int main() {
	ios::sync_with_stdio(false);
		
	return 0;
}
