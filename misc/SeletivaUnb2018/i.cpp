#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 1000;
bool is_composite[N];
vector<int>primes;

void sieve(){
	for(int i = 2 ; i < N ; i++){
		if(!is_composite[i]){
			for(int j = i * i ; j < N ; j += i){
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

int exp(int x, int e){
	int r = 1;
	
	while(e){
		r *= x;
	}
	
	return r;
}

int eulerTot(int n){
	int ans = n;
	
	for(int i = 0 ; i < primes.size() && primes[i] * primes[i] <= n ; i++){
		int power = 0;
		int k = primes[i];
		
		if(n % k == 0){
			ans -= ans / k;
		}
		
		while(n % k == 0){
			n /= k;
		}
	}
	
	if(n != 1){
		ans -= ans / n;
	}
	
	return ans;
}

int main(){
	sieve();
	
	for(int i = 2 ; i < 1000 ; i++){
		if(eulerTot(i) == 30)
			printf("%d\n", i);
	}
	
	return 0;
}