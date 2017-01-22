#include <stdio.h>
#include <string.h>

#define MAX (100010)
#define MOD (1000000007)

int dp[MAX];

long fact(int n) {
	if (n == 0 || n == 1)
		return 1;
	else if (dp[n] != -1)
		return dp[n];
	else {
		return dp[n] = (n % MOD * fact(n-1) % MOD) % MOD;
	}
}

int main()
{
	int t, i, n;

	memset(dp, -1, sizeof(dp));

    scanf("%d", &t);
    for (i = 0; i < t; i++) {
		scanf("%d", &n);
    	printf("%ld\n", fact(n));
    }
    
    return 0;
}
