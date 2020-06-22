#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
int a[N];

int main(){
	int n;

	cin >> n;

	for(int i = 0 ; i < n ; i++){
		cin >> a[i];

		if(a[i]){
			int l;
	
			cin >> l;

			a[l - 1] ^= 1;
			a[i + 1] ^= 1;
		}
	}

	for(int i = 1 ; i < n ; i++){
		a[i] ^= a[i - 1];
	}

	int cnt = 0;

	for(int i = 0 ; i < n ; i++){
		cnt += a[i];
	}

	cout << cnt << endl;

	return 0;
}