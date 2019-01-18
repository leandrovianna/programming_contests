#include <bits/stdc++.h>
using namespace std;

bool cond(char c){
	if('Q'==c || 'E'==c || 'R'==c || 'P'==c || 'S'==c || 'D'==c || 'F'==c || 'G'==c || 'Z'==c){
		return false;

	}
	if('L'==c || 'K'==c || 'J'==c || 'C'==c || 'B'==c || 'N'==c){
		return false;

	}
	
	return true;
}



int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	string st;
	bool dp[1005][1005];
	int q,n,r,resp;
	cin>>q;
	while(q--){
		cin>>st;
		n=st.size();
		resp=0;
		memset(dp,false,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int l=0;l<n-i;l++){
				r=l+i;
				if(i==0){
					if(cond(st[l])){
						dp[l][r]=true;
						resp=i+1;
					}else dp[l][r]=false;
				}else if(i==1){
					if(st[l]==st[r] && cond(st[l])){
						dp[l][r]=true;
						resp=i+1;
					}else dp[l][r]=false;
				}else{
					if(dp[l+1][r-1]==false){dp[l][r]=false;
					}else{
						if(st[l]==st[r] && cond(st[l])){
							//cout<<st[l+1]<<' '<<st[r-1]<<endl;
							dp[l][r]=true;
							resp=i+1;
						}else dp[l][r]=false;
					}

				}

			}
		}
		cout<<resp<<endl;
	}

}