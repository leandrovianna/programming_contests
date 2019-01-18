#include <bits/stdc++.h>

using namespace std;

typedef long long		ll;
typedef pair< ll, ll >	pii;
#define ft first
#define sd second


int main(){
	
	ll q,n,m,k,c;
	scanf("%lld",&q);
	pii vet[21];
	while(q--){
		ll resp=0LL,mx,my,sx,sy,tot=0LL;
		scanf("%lld %lld %lld",&n,&m,&k);
		ll x = m*(m+1)/2;
		tot = x*( n*(n+1)/2);
		for(int i = 0;i < k;i++)
			scanf("%lld %lld",&vet[i].ft,&vet[i].second);
			
		for(int i=1;i<(1<<k);i++){
			mx=my=c=0LL;
			sx=sy=100000LL;
			for(int j=0;j<k;j++){
				if((i&(1<<j))==(1<<j)){
					sx=min(sx,vet[j].ft);
					sy=min(sy,vet[j].sd);
					mx=max(mx,vet[j].ft);
					my=max(my,vet[j].sd);
					c++;
				}
			}
			//cout<<mx<<' '<<my<<' '<<sx<<' '<<sy<<endl;
			if(c%2==0)resp-=(n-mx+1)*(m-my+1)*(sx)*(sy);
			else resp+=(n-mx+1)*(m-my+1)*(sx)*(sy);

		}
		//cout<<tot<<' '<<resp<<endl;
		printf("%lld\n",tot-resp);	
	}

	return 0;
}