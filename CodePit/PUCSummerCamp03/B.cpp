//CodePit - New Year Tree - B
//Codeforces - New Year - 620C
#include <bits/stdc++.h>
using namespace std;

const int N = 400010;
int vet[N], cor[N], sub[N], inv[N];
vector<int> g[N];

int cnt;
int dfs(int v, int p) {
	vet[cnt] = v;
	inv[v] = cnt;
	cnt++;

	sub[v] = 0;
	for (vector<int>::iterator it = g[v].begin();
			it != g[v].end(); it++) {
		int u = *it;
		if (u == p) continue;

		sub[v] += 1 + dfs(u, v);
	}

	return sub[v];
}

// const int C = 62; // cores diferentes
struct node {
	int64_t mask;
};

const node ZERO = node();

node tree[4*N];
int lazy[4*N];

node combine(const node &n1, const node &n2) {
	node n;
	// for (int i = 1; i < C; i++) {
	// 	n.freq[i] = n1.freq[i] + n2.freq[i];
	// }

	n.mask = n1.mask | n2.mask;
	return n;
}

int count(node n) {
	int qtd = 0;
	for (int64_t x = n.mask; x > 0; x >>= 1) {
		if (x & 1) qtd++;
	}

	// for (int i = 1; i < C; i++) {
	// 	// cout << n.freq[i] << endl;
	// 	if (n.freq[i] > 0) {
	// 		qtd++;
	// 	}
	// }
	// cout << "count " << qtd << endl;

	return qtd;
}

void lazy_update(int idx, int l, int r) {
	int c = lazy[idx];
	// memset(tree[idx].freq, 0, sizeof(tree[idx].freq));
	// tree[idx].freq[c] = r - l + 1;
	tree[idx].mask = 1LL << c;

	if (l != r) {
		lazy[2*idx+1] = c;
		lazy[2*idx+2] = c;
	}

	lazy[idx] = 0;
}

void build(int idx, int l, int r) {
	if (l == r) {
		// tree[idx].freq[cor[vet[l-1]]] = 1;
		tree[idx].mask = 1LL << cor[vet[l-1]];
	} else {
		int mid = (l + r) >> 1;
		build(2*idx+1, l, mid);
		build(2*idx+2, mid+1, r);
		tree[idx] = combine(tree[2*idx+1], tree[2*idx+2]);
	}
}

node query(int idx, int l, int r, int x, int y) {
	if (lazy[idx] > 0)
		lazy_update(idx, l, r);

	if (l > y || r < x) {
		return ZERO;
	}

	if (x <= l && r <= y) {
		return tree[idx];
	} else {
		int mid = (l + r) >> 1;
		node lnode = query(2*idx+1, l, mid, x, y);
		node rnode = query(2*idx+2, mid+1, r, x, y);

		node r =  combine(lnode, rnode);
		return r;
	}
}

void update(int idx, int l, int r, int x, int y, int val) {
	if (lazy[idx] > 0)
		lazy_update(idx, l, r);

	if (l > y || r < x) {
		return;
	}

	if (x <= l && r <= y) {
		lazy[idx] = val;
		lazy_update(idx, l, r);
	} else {
		int mid = (l + r) >> 1;
		update(2*idx+1, l, mid, x, y, val);
		update(2*idx+2, mid+1, r, x, y, val);

		tree[idx] = combine(tree[2*idx+1], tree[2*idx+2]);
	}
}

int main() {
	ios::sync_with_stdio(false);

	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> cor[i];
	}

	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cnt = 0;
	dfs(1, 0);

	build(0, 1, n);

	int type;
	for (int i = 0; i < m; i++) {
		cin >> type;
		if (type == 1) {
			cin >> a >> b;
			int l = inv[a] + 1;
			int r = l + sub[a];
			update(0, 1, n, l, r, b);
		} else {
			cin >> a;
			int l = inv[a] + 1;
			int r = l + sub[a];
			cout << count(query(0, 1, n, l, r)) << endl;
		}
	}

	return 0;
}
