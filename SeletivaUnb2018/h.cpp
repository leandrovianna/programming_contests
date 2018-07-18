#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int N = 110;
ll dp[N];
ll used[N];
ll c[N][N];
char a[N];
int need = 0;
const ll mod = ll(1e9 + 7);

void pascal(){
	for(int i = 0 ; i < N ; i++){
		c[i][i] = 1LL;
		c[i][0] = 1LL;

		for(int j = 1 ; j < i ; j++){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			c[i][j] %= mod;
		}
	}
}

ll solve(int need){
	if(need <= 1)
		return 1LL;

	if(used[need]){
		return dp[need];
	}

	used[need] = 1LL;
	dp[need] = 0;
	
	for(int choose = 1 ; choose <= need ; choose++){
		dp[need] += c[need][choose] * solve(need - choose);
		dp[need] %= mod;
	}

	return dp[need];
}

int main (){
	int n;
	pascal();

	cin >> n;

	for(int i = 0 ; i < n ;i++){
		cin >> a[i];
	}

	for(int i = 0 ; i < n ; i++){
		char h;

		cin >> h;

		if(a[i] == 'o' && h == '.'){
			need++;	
		}

		if(a[i] == '.' && h == 'o'){
			cout << "0" << endl;
			return 0;
		}
	}
	
	if(need == 0){
		cout << 0 << endl;	
		return 0;
	}	
	cout << solve(need) << endl;

	return 0;
}