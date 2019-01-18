#include <bits/stdc++.h>

using namespace std;

const int N = int(1e7);
vector< int > primes;
bool is_composite[N];
bool dp[N];

void sieve(){
	for(int i = 2 ; i * i < N ; i++){
		if(!is_composite[i]){
			for(int j = i + i ; j < N ; j += i){
				is_composite[j] = true;
			}
		}
	}

	for(int i = 2 ; i < N ; i++){
		if(!is_composite[i]){
			primes.push_back(i);
		}
	}
}

int main(){
	int t;

	sieve();
	// printf("---\n");

	scanf("%d", &t);

	dp[1] = true;
	// printf("%lu\n", primes.size());
	int last = 0;

	for(int j = 3 ; j < N ; j++){
		int mid = (j + 1) / 2;

		while(last < primes.size() && mid >= primes[last + 1]){
			last++;
		}

		dp[j] = !dp[j - primes[last]];
	}
	// printf("sd\n");

	while(t--){
		int n;

		scanf("%d", &n);

		if(dp[n]){
			printf("first\n");
		}else{
			printf("second\n");
		}
	}

	return 0;
}