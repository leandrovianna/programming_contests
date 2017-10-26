#include <bits/stdc++.h>
using namespace std;
int pre[100005];
int suf[100005];
int v[100005];
int main()
{
	int n;
	cin >> n;
	string s = "";
	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	pre[0] = 0;
	for(int i = 1 ; i <= n; i++)
	{
		pre[i] += pre[i-1] + v[i];
		//cout << i << ' ' << pre[i] << '\n';
	}	
	suf[n+1] = 0;;
	for(int i = n ; i >= 1; i--)
		suf[i] += suf[i+1] + v[i];
	


	int ans = INT_MIN+100;
	int a;
	for(int i = 0; i <= (n >> 1); i++)
	{
		int j = n - n/2 + i + 1;

		int aux = pre[i] + suf[j];
		//cout << i << ' ' <<aux << '\n';
		if(aux > ans)
		{
			ans = aux;
			a = i;
		}
	}

	int cont = 0;
	for(int i = 0; i < a; i++)
	{
		cont++;
		s += 'L';
	}
	for(int i = 0; i < ((n >> 1) - cont); i++)
	{
		s += 'R';
	}
	cout << ans << '\n';
	cout << s << '\n';
	return 0;

}