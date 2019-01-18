#include <bits/stdc++.h>

using namespace std;

typedef long long 	ll;

const int N = int(1e5 + 10);
ll a[N];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		ll g = 0LL;
		int n;

		scanf("%d", &n);

		ll total = 0LL;

		for(int i = 0 ; i < n ; i++){
			scanf("%lld", &a[i]);
			g = __gcd(g, a[i]);
			total += a[i];
		}

		printf("%lld %lld\n", total, g);
	}

	return 0;
}