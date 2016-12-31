#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 100000

long long dp[MAXN];

long long fib(int n) {
	if (n == 1 || n == 2)
		return 1;
	else if (dp[n] == -1) {
		dp[n] = fib(n-2) + fib(n-1);
		return dp[n];
	}
	else return dp[n];
}

int main() {
	memset(dp, -1, MAXN);

	int i;
	cout << "Fibonacci - Digite o n: ";
	cin >> i;
	cout << "n-esimo termo: " << fib(i) << endl; 

	return 0;
}
