//HackerRank - Factorial Array - WCS12 D
#include <bits/stdc++.h>
using namespace std;

const int LIM = 1'000'000'010;
const int MOD = 1'000'000'000;
const int M = 50;
const int N = 100'100;
int fact[M];

int mod(int64_t v, int64_t mod = MOD) {
	if (v >= mod) return v % mod;
	else return v;
}

void pre_fact() {
	fact[0] = 1;
	for (int i = 1; i < M; i++) {
		fact[i] = mod((int64_t)fact[i-1] * i);
	}
}

int get_fact(int n) {
	if (n >= M) return 0;
	else return fact[n];
}

typedef struct {
	int freq[M];
	int sum;
} node;

node tree[4*N];
int lazy[4*N];

node combine(int idx) {
	node fnode;
	node &lnode = tree[2*idx+1];
	node &rnode = tree[2*idx+2];

	for (int i = 0; i < M; i++)
		fnode.freq[i] = lnode.freq[i] + rnode.freq[i];

	fnode.sum = mod(lnode.sum + rnode.sum);
	return fnode;
}

void lazy_update(int idx, int l, int r) {
	int x = lazy[idx];

	int freq_copy[M];
	for (int i = 0; i < M; i++) {
		freq_copy[i] = tree[idx].freq[i];
		tree[idx].freq[i] = 0;
	}

	for (int i = 0; i < M; i++) {
		if (i + x >= M) continue;

		tree[idx].freq[i+x] = freq_copy[i];
	}

	int &sum = tree[idx].sum;
	sum = 0;

	for (int i = 0; i < M; i++) {
		if (tree[idx].freq[i] > 0) {
			sum = mod(sum +
					mod(tree[idx].freq[i] * int64_t(get_fact(i))));
		}
	}

	if (l != r) {
		lazy[2 * idx + 1] += x;
		lazy[2 * idx + 2] += x;
	}

	lazy[idx] = 0;
}

void build(int idx, int l, int r, int v[]) {
	if (l == r) {
		if (v[l-1] < M)
			tree[idx].freq[v[l-1]] = 1;

		tree[idx].sum = get_fact(v[l-1]);
	} else {
		int mid = (l + r) >> 1;
		build(2 * idx + 1, l, mid, v);
		build(2 * idx + 2, mid+1, r, v);
		tree[idx] = combine(idx);
	}
}

int query(int idx, int l, int r, int i, int j) {
	if (lazy[idx] > 0)
		lazy_update(idx, l, r);

	assert(lazy[idx] == 0);

	if (j < l || i > r) {
		return 0;
	}
	else if (i <= l && r <= j) {
		return tree[idx].sum;
	} else {
		assert(l != r);

		int mid = (l + r) >> 1;
		int sum = 0;
		sum = mod(sum + query(2 * idx + 1, l, mid, i, j));
		sum = mod(sum + query(2 * idx + 2, mid+1, r, i, j));
		return sum;
	}
}

void update(int idx, int l, int r, int i, int j, int v = 1) {
	if (lazy[idx] > 0)
		lazy_update(idx, l, r);

	assert(lazy[idx] == 0);

	if (i <= l && r <= j) {
		lazy[idx] = v;
		lazy_update(idx, l, r);
	} else if (j >= l && i <= r) {
		assert(l != r);

		int mid = (l + r) >> 1;
		update(2 * idx + 1, l, mid, i, j, v);
		update(2 * idx + 2, mid+1, r, i, j, v);

		tree[idx] = combine(idx);
	}
}

void point_update(int idx, int l, int r, int i, int j, int v) {
	assert(i == j); //only point update

	if (lazy[idx] > 0)
		lazy_update(idx, l, r);

	assert(lazy[idx] == 0);

	if (i > r || j < l) return;

	if (i <= l && r <= j) {
		for (int i = 0; i < M; i++)
			tree[idx].freq[i] = 0;

		if (v < M)
			tree[idx].freq[v] = 1;

		tree[idx].sum = get_fact(v);
	} else {
		assert(l != r);

		int mid = (l + r) >> 1;
		point_update(2 * idx + 1, l, mid, i, j, v);
		point_update(2 * idx + 2, mid+1, r, i, j, v);

		tree[idx] = combine(idx);
	}
}

int main() {
	ios::sync_with_stdio(false);

	pre_fact();
	int n, m, t, a, b, v[N];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	build(0, 1, n, v);


	for (int i = 0; i < m; i++) {
		cin >> t >> a >> b;
		switch (t) {
			case 1:
				update(0, 1, n, a, b);
				break;
			case 2:
				cout << query(0, 1, n, a, b) << endl;
				break;
			case 3:
				point_update(0, 1, n, a, a, b);
				break;
		}
	}
	return 0;
}
