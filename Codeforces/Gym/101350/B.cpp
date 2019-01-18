#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	int t;

	cin >> t;

	while(t--){
		cin >> a >> b;

		if(a >= b){
			cout << "FunkyMonkeys" << endl;
		}else{
			cout << "WeWillEatYou" << endl;
		}
	}

	return 0;
}