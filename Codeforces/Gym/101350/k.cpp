#include <bits/stdc++.h>

using namespace std;

const int D = 10;
vector< int > v;
int qtd[D];
int tmp[D];

void calc(int number){
	while(number){
		tmp[number % 10]++;
		number /= 10;
	}

	int best = 0;

	for(int i = 0 ; i < D ; i++){
		best = max(best, tmp[i]);
	}

	for(int i = 0 ; i < D ; i++){
		if(tmp[i] == best){
			qtd[i]++;
		}
	}

	memset(tmp, 0, sizeof tmp);
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int a, b, n;

		scanf("%d %d %d", &a, &b, &n);

		for(int i = 1 ; i * i <= n ; i++){
			int val = a * i * i + b * i;

			if(val > n){
				break;
			}

			v.push_back(val);
		}

		if(v.size() == 0){
			printf("-1\n");
			continue;
		}

		for(int i = 0 ; i < v.size() ; i++){
			calc(v[i]);
		}

		int best = 0;

		for(int i = 0 ; i < D ; i++){
			best = max(best, qtd[i]);
		}

		for(int i = 0 ; i < D ; i++){
			if(qtd[i] == best){
				printf("%d\n", i);
				break;
			}
		}

		memset(qtd, 0, sizeof qtd);
		v.clear();
	}

	return 0;
}