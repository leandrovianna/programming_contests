#include<bits/stdc++.h>
using namespace std;
#define int long long
bool notprime(int prime)
{
	for (int i = 2; i*i <=prime ; ++i)
	{
		if(prime%i==0)
			return true;
	}
	return false;
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int p,q;
		p=q=1;
		int prime=2;
		while(p*prime<n)
		{
			// cout<<prime<<"\n";
			q*=(prime+1);
			p*=(prime);
			prime++;
			while(notprime(prime))
			{
				prime++;
			}
		}

		int gc=__gcd(p,q);
		cout<<p/gc<<"/"<<q/gc<<"\n";
	}
	return 0;
}
