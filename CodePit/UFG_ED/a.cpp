#include <iostream>
//SPOJ - GSS1
#include <algorithm>
#include <climits>

const int N = 1e6;
const int NINF = INT_MIN;

typedef struct {
	int prefix;
	int suffix;
	int sum;
	int max;
} node;

node tree[4*N];
int v[N];

node make_node(int x) {
	node n;
	n.sum = x;
	n.prefix = n.suffix = n.max = x;
	return n;
}

node combine(node a, node b) {
	node c;
	c.sum = a.sum + b.sum;	
	c.prefix = std::max(a.prefix, a.sum + b.prefix);
	c.suffix = std::max(b.suffix, a.suffix + b.sum);
	c.max = std::max(
			std::max(a.max, b.max),
			a.suffix + b.prefix
		);
	return c;
}

void construct(int idx, int l, int r) {
	if (l == r) tree[idx] = make_node(v[l]);
	else {
		int h = (l + r) >> 1;
		construct(2*idx+1, l, h);
		construct(2*idx+2, h+1, r);
		tree[idx] = combine(tree[2*idx+1], tree[2*idx+2]);
	}
}

node query(int idx, int l, int r, int x, int y) {
	if (x > r || y < l) return make_node(NINF);
	if (x <= l && r <= y) {
		return tree[idx];
	}

	int h = (l + r) >> 1;
	if (y <= h) return query(2*idx+1, l, h, x, y);
	if (x > h) return query(2*idx+2, h+1, r, x, y);

	return combine(
			query(2*idx+1, l, h, x, h),
			query(2*idx+2, h+1, r, h+1, y)
			);
	// node a = query(2*idx+1, l, h, x, y);
	// node b = query(2*idx+2, h+1, r, x, y);
    //
	// if (a.sum == NINF)
	// 	return b;
	// else if (b.sum == NINF)
	// 	return a;
	// else
	// 	return combine(a, b);
}

int main() {
	int n, m, x, y;
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> v[i];

	construct(0, 0, n-1);

	std::cin >> m;
	while (m--) {
		std::cin >> x >> y;
		std::cout << query(0, 0, n-1, x-1, y-1).max << std::endl;
	}

	return 0;
}

