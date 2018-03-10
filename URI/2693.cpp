//URI - Van - 2693
#include <bits/stdc++.h>
using namespace std;

struct aluno {
	string nome;
	char regiao;
	int custo;
};

bool operator<(aluno a, aluno other) {
	return a.custo < other.custo
		|| (a.custo == other.custo && a.regiao < other.regiao)
		|| (a.custo == other.custo && a.regiao == other.regiao
				&& a.nome < other.nome);
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	const int N = 10000;
	aluno alunos[N];

	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> alunos[i].nome
				>> alunos[i].regiao
				>> alunos[i].custo;
		}

		sort(alunos, alunos+n);

		for (int i = 0; i < n; i++) {
			cout << alunos[i].nome << endl;
		}
	}

	return 0;
}
