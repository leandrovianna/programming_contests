#include <bits/stdc++.h>
using namespace std;
int v[10005];
map<pair<int,int>, pair<string,int> >dp;
int n;

pair<string,int> solve(int qt, int i, int j, string s)
{
	if(qt == ((n >> 1)))
		return make_pair(s,0);
	pair<string, int> ans = make_pair("",INT_MIN);
	
	if(dp.count(make_pair(i,j)))
		return dp[make_pair(i,j)];
	
	pair<string,int>aux = solve(qt+1,i+1,j,s +'L');

	if(aux.second + v[i] > ans.second)
	{
		ans.second = aux.second + v[i];
		ans.first = aux.first;
	}
	
	aux = solve(qt+1,i,j-1,s +'R');
	
	if(aux.second + v[j] > ans.second)
	{
		ans.second = aux.second + v[j];
		ans.first = aux.first;
	}

	return dp[make_pair(i,j)] = ans;
}
int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&v[i]);
	}
	pair<string,int> ans = solve(0,0,n-1,"");
	cout << ans.second << '\n' << ans.first << '\n';
	return 0;
}