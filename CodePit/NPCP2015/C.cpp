#include <bits/stdc++.h>
using namespace std ;
#define inf 0x3F3F3F3F
string a, b ;
int main(){
	cin >> a;
	b = "";
	for (int i = 0; i < a.size()/3; i++) b += "PER";

	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) ans++;
	}

	cout << ans << endl;
    return 0;
}
