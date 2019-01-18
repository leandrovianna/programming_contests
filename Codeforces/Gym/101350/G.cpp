#include <bits/stdc++.h>

using namespace std;

typedef long long		ll;
typedef pair< ll, ll >	pii;

const int N = 30, M = 1e4 + 10;
pii p[N];
ll n, m, k;
ll tot;
int mark[M];
int cur[M];
vector< ll > col;
vector< ll > adj[M];
int test = 1;
int runn = 1;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){

		scanf("%lld %lld %d", &n, &m, &k);

		for(int i = 0 ; i < k ; i++){
			scanf("%d %d", &p[i].first, &p[i].second);

			adj[p[i].first].push_back(p[i].second);
			mark[p[i].second] = test;
		}

		for(ll i = 1LL ; i < M ; i++){
			if(mark[i] == test){
				col.push_back(i);
			}
		}

		ll ret = 0LL;
		ll past = ((1LL + m) * m) / 2LL;

		for(int i = 1 ; i <= n ; i++){
			ll tot1 = 0LL;

			for(int j = i ; j <= n ; j++){
				ll add = 0LL;

				if(adj[j].size() == 0){
					// printf("%d, %d + %lld\n", i, j, past);
					ret += past;
					continue;
				}

				for(int t = 0 ; t < adj[j].size() ; t++){
					cur[adj[j][t]] = runn;
					// printf("marking em %d, %d\n", i, j);
				}

				ll last = 1LL;

				for(int j = 0 ; j < col.size() ; j++){
					if(cur[col[j]] == runn && last < col[j]){
						ll nem = (col[j] - 1LL) - last + 1LL;
						// printf("entrei %lld %d, %lld\n", col[j] + 1LL, i, ((last + col[j] - 1LL) * nem) / 2LL);

						add += ((1LL + nem) * nem) / 2LL;
						last = col[j] + 1LL;
					}else if(cur[col[j]] == runn){
						last = max(last, col[j] + 1LL);
					}
				}

				if(last <= m){
					ll nem = m - last + 1LL;

					add += ((1LL + nem) * nem) / 2LL;
					// printf("entrei aqui! + %lld %lld %lld\n", ((last + m) * nem) / 2LL, nem, last);
				}

				// if(adj[j].size() == 0){
				// 	assert(past == add);
				// }

				past = add;
				// if(i != 1)
				ret += add;

				tot1 += add;
				// printf("%d, %d + %lld %lld\n", i, j, add, last);
			}

			// if(i == 1){
			// 	printf("tot1 = %lld\n", tot1);
			// }

			past = ((1LL + m) * m) / 2LL;

			runn++;
		}

//		ll tot = ((n * m) * (n * m - 1LL)) / 2LL + (n * m);

		printf("%lld\n", ret);

		for(int i = 0 ; i < k ; i++){
			adj[p[i].first].clear();
		}

		col.clear();
		test++;
	}

	return 0;
}