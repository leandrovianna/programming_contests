//TAP BOCA - Acordes Intergalaticos - A5
#include <bits/stdc++.h>
using namespace std;

const int M = 9;
const int N = 1e5+10;

struct node {
	int freq[M];
} tree[4*N];

const struct node NIL = {};

int lazy[4*N];

void build(int idx, int l, int r) {
	if (l == r) {
		memset(tree[idx].freq, 0, sizeof(tree[idx].freq));
		tree[idx].freq[1] = 1;
	}
	else {
		int mid = (l + r) / 2;
		build(2*idx+1, l, mid);
		build(2*idx+2, mid+1, r);

		for (int i = 0; i < M; i++) {
			tree[idx].freq[i] = tree[2*idx+1].freq[i] + tree[2*idx+2].freq[i];
		}
	}
}

int moreFrequent(struct node no) {
	int maxi = -1, mx = -1;
	for (int i = 0; i < M; i++) {
		if (no.freq[i] >= mx) {
			mx = no.freq[i];
			maxi = i;
		}
	}
	return maxi;
}

struct node combine(struct node t1, struct node t2) {
	struct node comb;
	for (int i = 0; i < M; i++)
		comb.freq[i] = t1.freq[i] + t2.freq[i];
	return comb;
}


void lazy_update(int idx, int l, int r) {
	assert(lazy[idx] >= 0);

	int copy[M];
	for (int i = 0; i < M; i++) {
		copy[i] = tree[idx].freq[i];
	}
	for (int i = 0; i < M; i++) {
		tree[idx].freq[(i + lazy[idx]) % M] = copy[i];
	}

	if (l != r) {
		lazy[2*idx+1] += lazy[idx];
		lazy[2*idx+2] += lazy[idx];
	}

	lazy[idx] = 0;
}

void update(int idx, int l, int r, int a, int b, int val) {
	//note: in update, verify by lazy update even node isn't inner the interval
	//because, a father node will update with its value
	if (lazy[idx] > 0) lazy_update(idx, l, r);

	assert(lazy[idx] == 0);

	if (a > r || b < l) return;

	if (a <= l && r <= b) {
		lazy[idx] = val;
		lazy_update(idx, l, r);
		return;
	}
	
	if (l != r) {
		int mid = (l + r) / 2;
		update(2*idx+1, l, mid, a, b, val);
		update(2*idx+2, mid+1, r, a, b, val);

		for (int i = 0; i < M; i++) {
			tree[idx].freq[i] = tree[2*idx+1].freq[i] + tree[2*idx+2].freq[i];
		}
	}
}

struct node query(int idx, int l, int r, int a, int b) {
	if (a > r || b < l) return NIL;

	if (lazy[idx] > 0) lazy_update(idx, l, r);

	assert(lazy[idx] == 0);

	if (a <= l && r <= b) {
		return tree[idx];
	}
	
	if (l != r) {
		int mid = (l + r) / 2;
		struct node left = query(2*idx+1, l, mid, a, b);
		struct node right = query(2*idx+2, mid+1, r, a, b);

		struct node ans;
		for (int i = 0; i < M; i++) {
			ans.freq[i] = left.freq[i] + right.freq[i];
		}

		return ans;
	}

	return NIL;
}

int main() {
	ios::sync_with_stdio(false);
	int n, q, a, b;
	cin >> n >> q;

	build(0, 0, n-1);

	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		int f = moreFrequent(query(0, 0, n-1, a, b));
		update(0, 0, n-1, a, b, f);
	}

	for (int i = 0; i < n; i++) {
		cout << moreFrequent(query(0, 0, n-1, i, i)) << '\n';
	}
	return 0;
}
