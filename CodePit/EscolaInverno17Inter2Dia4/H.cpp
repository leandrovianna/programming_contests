#include <bits/stdc++.h>

#define	MAXIMO	1100

using namespace std;

vector<int>grafo[MAXIMO];
int qtd[MAXIMO];
int cor[MAXIMO];

void dfs(int x){
	cor[x] = 1;

	for(int i = 0 ; i < grafo[x].size() ; i++){
		if(cor[grafo[x][i]] == 0){
			qtd[grafo[x][i]]++;
			cor[grafo[x][i]] = 1;
			dfs(grafo[x][i]);
		}
	}
}

int main (){
	int k, n, m;
	set<int>vertices;
	
	scanf("%d%d%d", &k, &n, &m);

	int x;

	for(int i = 0 ; i < k ; i++){
		scanf("%d",	&x);

		vertices.insert(x);
	}
	
	for(int i = 1 ; i <= n ; i++)
		qtd[i] = 0;
	
	for(int i = 0 ; i < m ; i++){
		int a, b;

		scanf("%d%d", &a, &b);

		grafo[a].push_back(b);
	}
		
	for(set<int>::iterator it = vertices.begin();
			it != vertices.end(); it++) {
		for(int j = 1 ; j <= n ; j++){
			cor[j] = 0;
		}
		qtd[*it]++;
		dfs(*it);
	}

	int r = 0;
	for (int i = 1; i <= n; i++) {
		if(qtd[i] == vertices.size()){
			r++;}
	}

	printf("%d\n", r);
	
	return 0;
}
