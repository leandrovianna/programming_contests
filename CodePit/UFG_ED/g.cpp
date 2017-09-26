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

const int N = 1e5+10;

typedef struct {
	int r0, r1, r2;
	// resto 0, resto 1, resto 2 (divisao por 3)
} node;

const node NODE_DEFAULT = {1,0,0};
const node NODE_NULL = {0,0,0};

node tree[4*N];
int lazy[4*N];

node combine(node l, node r) {
	node c;
	c.r0 = l.r0 + r.r0;
	c.r1 = l.r1 + r.r1;
	c.r2 = l.r2 + r.r2;
	return c;
}

void lazy_update(int idx, int l, int r) {
	int lz = lazy[idx];
	int r0 = tree[idx].r0,
		r1 = tree[idx].r1,
		r2 = tree[idx].r2;

	if (l != r) {
		lazy[2*idx+1] += lz;
		lazy[2*idx+2] += lz;
	}

	switch (lz % 3) {
		case 1: 
			tree[idx].r0 = r2;
			tree[idx].r1 = r0;
			tree[idx].r2 = r1;
			break;
		case 2:
			tree[idx].r0 = r1;
			tree[idx].r1 = r2;
			tree[idx].r2 = r0;
			break;
	}

	lazy[idx] = 0;
}

void build(int idx, int l, int r) {
	if (l == r) tree[idx] = NODE_DEFAULT;
	else {
		int h = (l + r) >> 1;
		build(2*idx+1, l, h);
		build(2*idx+2, h+1, r);
		tree[idx] = combine(tree[2*idx+1], tree[2*idx+2]);
	}
}

void update(int idx, int l, int r, int x, int y) {
	if (lazy[idx] > 0) {
		lazy_update(idx, l, r);
	}

	if (x <= l && r <= y) {
		lazy[idx] = 1; // force update
		lazy_update(idx, l, r);	
		return;
	}

	if (l > y || r < x) return;

	if (l != r) {
		int h = (l + r) >> 1;
		update(2*idx+1, l, h, x, y);
		update(2*idx+2, h+1, r, x, y);
		tree[idx] = combine(tree[2*idx+1], tree[2*idx+2]);
	}
}

node query(int idx, int l, int r, int x, int y) {
	if (lazy[idx] > 0) lazy_update(idx, l, r);

	if (x <= l && r <= y) {
		return tree[idx];
	}

	if (l > y || r < x) return NODE_NULL;

	if (l != r) {
		int h = (l + r) >> 1;
		node a = query(2*idx+1, l, h, x, y);
		node b = query(2*idx+2, h+1, r, x, y);
		return combine(a, b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, q, o, a, b;
	node nx;

	cin >> n >> q;

	build(0, 0, n-1);

	while (q--) {
		cin >> o >> a >> b;
		if (o == 0)
			update(0, 0, n-1, a, b);
		else {
			nx = query(0, 0, n-1, a, b);
			cout << nx.r0 << endl;
		}
	}
	return 0;
}
