#include <iostream>
using namespace std;int main(){int i,j,t,n,x,r,v[110][110];cin>>t;while(t--){cin>>n>>v[0][0];r=0;for(i=1;i<n;i++)for(j=0;j<n;j++){if(j<=i){cin>>x;r=max(r,v[i][j]=max(v[i-1][j==0?j:j-1],v[i-1][j])+x);}else v[i][j]=0;}cout<<r<<endl;}return 0;}
