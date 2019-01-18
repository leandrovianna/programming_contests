#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(2e5 + 10);
char s[N];
ll q[3];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		scanf("\n%s", s);
		// printf("%s\n", s);

		q[0] = 1LL;
		int ac = 0;
		ll carry = 1LL;
		ll tot = 0LL;

		for(int i = 0 ; i < n ; i++){
			ll ret = 0LL;

			if(s[i] == '1'){
				ret = carry;
				carry = 1LL;
				ac = (ac + 1) % 2;
			}else{
				if(q[1])
					ret = 1LL;
				carry++;
			}

			if(ac == 1){
				tot += q[0] - ret;
				// printf("%d +%lld %lld %lld\n", i, q[0] - ret, q[0], ret);
			}else{
				tot += q[1] - ret;
				// printf("%d +%lld\n", i, q[1] - ret);
			}

			q[ac]++;
		}

		printf("%lld\n", tot);

		memset(q, 0, sizeof q);
	}

	return 0;
}