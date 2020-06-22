#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
int last[N];
int ans[N];
int a[N];

int main (){
	int n;

	cin >> n;
	
	for(int i = 1 ; i < N ; i++){
		last[i] = -1;
	}

	for(int i = 0 ; i < n ; i++){
		int x;

		cin >> x;
		a[i] = x;

		ans[x] = max(ans[x], i - last[x]);
		last[x] = i;
	}
	
	int best = 10000000;
	int idx = 0;

	for(int i = 0 ; i < n ; i++){
		int x = a[i];

		ans[x] = max(ans[x], n - last[x]);

		if(best > ans[x]){
			idx = x;
			best = ans[x];
		}
	}

	cout << best << ' ' << idx << endl;
	
	return 0;
}