//HackerRank - Breaking Sticks - WCS 12 C
#include <bits/stdc++.h>
using namespace std;

const int N = 10000000 ;
int lp [ N + 1 ] ;
vector < int > pr ;
void sieve() {

	for ( int i = 2 ; i <= N ; ++ i ) {
		if ( lp [ i ] == 0 ) {
			lp [ i ] = i ;
			pr. push_back ( i ) ;
		}
		for ( int j = 0 ; j < ( int ) pr. size ( ) && pr [ j ] <= lp [ i ] && i * pr [ j ] <= N ; ++ j )
			lp [ i * pr [ j ] ] = pr [ j ] ;
	}
}

int64_t best(int64_t l) {
	// cout << l << endl;

	if (l == 1) return 1;

	if (l > N) l = 1'000'010;

	auto it = lower_bound(pr.begin(), pr.end(), l);

	for (; it >= pr.begin(); it--) {
		if (l % *it == 0) {
			// cout << l << " " << *it << endl;
			auto a = best(l / *it);
			// cout << l << " " << 1 + *it * a << endl;
			return 1 + *it * a;
		}
	}

	// cout << "bingo " << l+1 << endl;
	return 1 + l;
}

int main() {
	ios::sync_with_stdio(false);

	sieve();

	int n;
	int64_t a[110];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int64_t ans = n;
	for (int i = 0; i < n; i++) {
		int64_t x = a[i];
		for (const auto &p : pr) {
			while (x % p == 0) {
				ans += x;
				x /= p;
			}
		}

		if (x > 0)
			ans += x;
	}

	cout << ans << endl;
	return 0;
}
