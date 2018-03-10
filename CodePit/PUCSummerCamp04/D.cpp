//CodePit - Digitando no Telefone Celular - D
#include <bits/stdc++.h>
using namespace std;

const int M = 1000010;
const int E = 30;

int trie[M][E];
int trieId[M];
int qtd[M];
int cnt = 1;
int n;

void add(string str, int id) {
	int no = 0;
	for (const auto &c : str) {
		int x = c - 'a';
		if (trie[no][x] == -1) {
			qtd[no]++;
			trie[no][x] = cnt;
			no = cnt;
			cnt++;
		} else {
			no = trie[no][x];
		}
	}

	trieId[no] = id;
}

double dfs(int no, int types) {
	double r = 0;

	int x = (no == 0 || qtd[no] > 1 || trieId[no] != -1 ? types+1 : types);

	for (int i = 0; i < E; i++) {
		if (trie[no][i] != -1) {
			r += dfs(trie[no][i], x);
		}
	}

	if (trieId[no] != -1) {
		r += (double) types / n;
	}

	return r;
}

int main() {
	ios::sync_with_stdio(false);

	string str;
	while (cin >> n) {
		memset(trie, -1, sizeof(trie));
		memset(trieId, -1, sizeof(trieId));
		memset(qtd, 0, sizeof(qtd));

		for (int i = 0; i < n; i++) {
			cin >> str;
			add(str, i+1);
		}

		cout << fixed << setprecision(2)
			<< dfs(0, 0) << endl;
	}

	return 0;
}
