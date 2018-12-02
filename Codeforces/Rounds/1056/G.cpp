#include <bits/stdc++.h>
using namespace std;


#define ft first
#define sd second
const int N=1005;


int main(){
    int n,k,x,y,resp;
    pair<int,int> vet[N];
    cin>>n;
    for(int i=0;i<n;i++)cin>>vet[i].ft>>vet[i].sd;

    resp=0;
    for(int i=0;i<n;i++){
    	x=vet[i].ft;
    	y=vet[i].sd;
    	k=1;
    	for(int j=0;j<n;j++){
    		if(i!=j){
    			if(vet[j].ft >= x || y <= vet[j].sd){
    				k++;
    				x=max(vet[j].ft,x);
    				y=min(vet[j].sd,y);
    			}
    		}
    	}
    	if(k>resp && k>=x && k<=y)resp=k;
    }
    if(resp==0)cout<<"-1\n";
    else cout<<resp<<"\n";

    return 0;
}
