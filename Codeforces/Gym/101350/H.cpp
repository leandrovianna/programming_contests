#include <bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	string st;
	int q,n;
	cin>>q;
	while(q--){
		cin>>st;
		n=st.size();
		if(st.find('Q')!=string::npos || st.find('E')!=string::npos || st.find('R')!=string::npos || st.find('P')!=string::npos){
			cout<<"no\n";
			continue;
		}
		if(st.find('S')!=string::npos || st.find('D')!=string::npos || st.find('F')!=string::npos || st.find('G')!=string::npos){
			cout<<"no\n";
			continue;
		}
		if(st.find('Z')!=string::npos || st.find('L')!=string::npos || st.find('K')!=string::npos || st.find('J')!=string::npos){
			cout<<"no\n";
			continue;
		}
		if(st.find('C')!=string::npos || st.find('B')!=string::npos || st.find('N')!=string::npos){
			cout<<"no\n";
			continue;
		}
		bool ver=true;
		for(int i=0;i<=n/2;i++){
			if(st[i]!=st[n-i-1]){
				ver=false;
			}
		}
		if(ver){
			cout<<"yes\n";
		}else{
			cout<<"no\n";
		}
	}

}