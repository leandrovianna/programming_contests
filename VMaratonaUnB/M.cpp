#include <bits/stdc++.h>

using namespace std;

const int N = 100100;
int f[N];
int tree[N << 3];
int n;

void build(int node, int i, int j){
	if(i == j){
		tree[node] = f[i];
	}else{
		int left = node * 2 ;
		int right = node * 2 + 1;

		build(left, i, (i + j) / 2);
		build(right, (i + j) / 2 + 1, j);

		tree[node] = __gcd(tree[left], tree[right]);
	}
}

int query(int node, int i, int j, int x, int y){
	if(i > y || j < x){
		return -1;
	}

	if(i >= x && j <= y){
		return tree[node];
	}else{
		int left = node * 2;
		int right = node * 2 + 1;

		int a = query(left, i, (i + j) / 2, x, y);
		int b = query(right, (i + j) / 2 + 1, j, x, y);

		if(a == -1)
			return b;
		if(b == -1)
			return a;

		return __gcd(a, b);
	}
}

int main (){
	int t;

	cin >> t;

	while(t--){
		int m;

		cin >> n >> m;

		for(int i = 1 ; i <= n ; i++)
			cin >> f[i];

		build(1, 1, n);

		for(int i = 0 ; i < m ; i++){
			int l, r;

			cin >> l >> r;

			cout << query(1, 1, n, l, r);

			if(i < m - 1)
				cout << " ";

		}

		cout << '\n';
	}

	return 0;
}