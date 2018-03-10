//CodePit - Watto and Mechanism - G
#include <bits/stdc++.h>
using namespace std;

const int M = 6 * 100100;
const int E = 3; //a, b, c
int cnt = 1;

int trie[M][E];
int fim[M];

void add(string str) {
	int no = 0;
	for (const auto &c : str) {
		int x = c - 'a';
		if (trie[no][x] == 0) {
			trie[no][x] = cnt;
			no = cnt;
			cnt++;
		} else {
			no = trie[no][x];
		}
	}

	fim[no] = 1;
}

string w;
bool search(int node, size_t i, bool mismatch) {
	if (i == w.size()) {
		return mismatch && fim[node];
	}

	int x = w[i] - 'a';

	if (trie[node][x]) {
		if (search(trie[node][x], i+1, mismatch)) {
			return true;
		}
	}

	if (mismatch) return false;

	for (int j = 0; j < E; j++) {
		if (j == x) continue;
		if (trie[node][j] && search(trie[node][j], i+1, true)) {
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> w;
		add(w);
	}

	for (int i = 0; i < m; i++) {
		cin >> w;
		cout << (search(0, 0, false) ? "YES" : "NO") << endl;
	}

	return 0;
}
