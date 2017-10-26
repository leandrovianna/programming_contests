#include <bits/stdc++.h>

using namespace std;
int succ[10];
int ant[10];
int main (){
	int n,k;
	for(int i = 0; i < 10; i++)
	{
		ant[i] = ((i-1) + 10)%10;;
		succ[i] = ((i+1) + 10)%10;;
	}

	cin >> n >> k;
	string s,t;
	cin >> t >> s;
	bool ok = 1;
	int cont = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == t[i])
			continue;
		int a = t[i] - '0';
		int b = s[i] - '0';
		if( a == ant[b] || a == succ[b])
			cont++;
		else
			ok = 0;
	}
	if(cont > k)
		ok = 0;
	if(ok)
		cout << "Acesso garantido\n";
	else
		cout << "Acesso negado\n";
	return 0;
}