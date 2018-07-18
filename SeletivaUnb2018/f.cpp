#include <bits/stdc++.h>

using namespace std;

const int N = 42;
int dp[N][N][N][N];
int used[N][N][N][N];
char t[N][N];

bool ok(int i, int j, int ie, int je){
	char c = t[i][j];

	for(int ki = i ; ki <= ie ; ki++){
		for(int kj = j ; kj <= je ; kj++){
			if(t[ki][kj] != c){
				return false;
			}
		}
	}

	return true;
}

int solve(int i, int j, int ie, int je){
	int &ans = dp[i][j][ie][je];
	
	if(used[i][j][ie][je]){
		return ans;
	}

	used[i][j][ie][je] = 1;

	if(ok(i, j, ie, je)){
		return ans = 0;
	}

	ans = 1e9;

	for(int ki = i ; ki <= ie && (ie - ki) >= 1 ; ki++){
		ans = min(ans, 1 + solve(i, j, ki, je) + solve(ki + 1, j, ie, je));
	}

	for(int kj = j ; kj <= je && (je - kj) >= 1 ; kj++){
		ans = min(ans, 1 + solve(i, j, ie, kj) + solve(i, kj + 1, ie, je));
	}

	return ans;
}

int main(){
	int n;
	
	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			scanf("\n%c", &t[i][j]);
		}
	}
	
	printf("%d\n", solve(0, 0, n - 1, n - 1));	

	return 0;
}