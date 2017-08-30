//1477 - URI - Homem, Elefante e Rato
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
	int h, e, r;
} node;

const node NODE_DEFAULT = {0, 0, 0};

node node_sum(node a, node b) {
	node result;
	result.h = a.h + b.h;
	result.e = a.e + b.e;
	result.r = a.r + b.r;
	return result;
}

node tree[2*N+N];
int lazy[2*N+N];

void construct(int idx, int l, int r) {

	lazy[idx] = 0;

	if (l == r) {
		tree[idx] = NODE_DEFAULT;
		tree[idx].h = 1;
	}
	else {
		int half = (l + r) >> 1;
		construct(2*idx+1, l, half);
		construct(2*idx+2, half+1, r);

		tree[idx] = node_sum(tree[2*idx+1], tree[2*idx+2]);
	}
}

void changeStrategy(int idx, int q) {
	int v = q % 3, tmp;

	node &x = tree[idx];

	switch (v) {
		case 1:
			tmp = x.h;
			x.h = x.r;
			x.r = x.e;
			x.e = tmp;
			break;
		case 2:
			tmp = x.r;
			x.r = x.h;
			x.h = x.e;
			x.e = tmp;
			break;
	}
}

void lazy_propagation(int idx, int l, int r) {
	// calculate for this node
	changeStrategy(idx, lazy[idx]);

	//put 'flag' in the children
	if (l != r) {
		lazy[2*idx+1] += lazy[idx];
		lazy[2*idx+2] += lazy[idx];
	}

	// remove 'flag'
	lazy[idx] = 0;
}

node query(int idx, int l, int r, int x, int y) {
	if (lazy[idx] > 0) 
		lazy_propagation(idx, l, r);

	if (x > r || y < l) return NODE_DEFAULT;
	if (x <= l && r <= y) return tree[idx];

	int h = (l + r) >> 1;
	node left = NODE_DEFAULT;
	node right = NODE_DEFAULT;

	left = query(2*idx+1, l, h, x, y);
	right = query(2*idx+2, h+1, r, x, y);

	return node_sum(left, right);
}

void update(int idx, int l, int r, int x, int y) {
	if (lazy[idx] > 0) 
		lazy_propagation(idx, l, r);
	
	if (x > r || y < l) return;
	if (x <= l && r <= y) {
		//lazy propagation
		//calculate for this node
		changeStrategy(idx, 1);

		//put 'flag' in the children
		if (l != r) {
			lazy[2*idx+1]++;
			lazy[2*idx+2]++;
		}
		return;
	}

	if (l != r) {
		int h = (l + r) >> 1;
		update(2*idx+1, l, h, x, y);
		update(2*idx+2, h+1, r, x, y);
		tree[idx] = node_sum(tree[2*idx+1], tree[2*idx+2]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, a, b;
	char c;

	while (cin >> n >> m) {
		construct(0, 1, n);

		while (m--) {
			cin >> c >> a >> b;
			switch (c) {
				case 'C':
					node t;
					t = query(0, 1, n, a, b);
					cout << t.h << " " << t.e << " " << t.r << endl;
					break;
				case 'M':
					update(0, 1, n, a, b);
					break;
			}
		}
		cout << endl;
	}

	return 0;
}
