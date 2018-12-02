#include <bits/stdc++.h>
using namespace std;


#define ft first
#define sd second
const int N=1005;


int main(){
    int n,k,resp;
    pair<int,int> vet[N];
    cin>>n;
    for(int i=0;i<n;i++)cin>>vet[i].ft>>vet[i].sd;

    resp=0;
    for(int i=1;i<=n;i++){
    	k=0;
    	for(int j=0;j<n;j++){
    		if ((vet[j].ft <= i && i <= vet[j].sd)) {
				k++;
    		}
    	}
    	if(k==i)resp=k;
    }

    if(resp==0)cout<<"-1\n";
    else cout<<resp<<"\n";

    return 0;
}
