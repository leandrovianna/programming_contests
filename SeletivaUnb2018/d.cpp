#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>	pii;
const int N = int(1e6 + 10);
vector<pii>p;
typedef long long	ll;
int a[N];
int n;

bool fit(int i, int j){
	int mx = (1 << p[j].second) - 1;

	for(int k = 0 ; k + i < n && k < p[j].first ; k++){
		if(a[k + i] > mx){
			return false;
		}
	} 

	return true;
}

ll much(int i, int k){
	return min(n - i, p[k].first);
}

int main(){
	p.push_back({28, 1});
	p.push_back({14, 2});
	p.push_back({9, 3});
	p.push_back({7, 4});
	p.push_back({5, 5});
	p.push_back({4, 7});
	p.push_back({3, 9});
	p.push_back({2, 14});
	p.push_back({1, 28});
	
	cin >> n;

	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	
	ll cnt = 0;

	for(int i = 0 ; i < n ; i++){
		for(int k = 0 ; k < p.size() ; k++){
			if(fit(i, k)){
				cnt += 32LL;
				i += p[k].first - 1;
				break;
			}
		}
	}

	cout << "Total bytes: " << cnt / 8LL << endl;

	return 0;
}