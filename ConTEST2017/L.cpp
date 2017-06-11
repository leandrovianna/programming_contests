#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

const int M = 1e9 + 7;
const int N = 1010;
const int P = 1010;

i32 dp[N][P];

i32 fact(int n) {
	i32 r = 1;
	for (int i = 2; i <= n; i++) 
		r = (r % M * i % M) % M;

	return r % M;
}

i32 d, x, y;
void extendedEuclid(i32 A, i32 B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        i32 temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

i32 comb(int a, int b) {
	i32 r = 1;
	for (int i = a-b+1; i <= a; i++)
		r = (r % M * i % M) % M;

	extendedEuclid(fact(b), M);
	i32 q = (x % M + M) % M;

	return (r % M * q % M) % M;
}

i32 solve(int n, int p, int m) {

	if (n < m) return 0;
	if (p == 1) return 1;
	
	if (dp[n][p] != -1) return dp[n][p];

	i32 s = 0;
	s = ( (p % M * solve(n-1, p, m) % M) % M + (comb(n-1, m-1) % M * solve(n-m, p-1, m) % M) % M ) % M;

	return dp[n][p] = s;
}

int main() {
	int n, p, m, c;	
	i32 r;

	for (int i = 0; i < N; i++)
		memset(dp[i], -1, sizeof(dp[i]));

	cin >> m;
	cin >> c;
	for (int ci = 1; ci <= c; ci++) {
		cin >> n >> p;

		r = (fact(p) % M * solve(n, p, m) % M) % M;

		cout << "Cenario " << ci << ": " << r << endl;
	}
	return 0;
}
