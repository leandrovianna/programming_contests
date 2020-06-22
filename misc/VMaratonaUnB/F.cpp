#include <bits/stdc++.h>

using namespace std;

const int M = 61;
const int T = 101;

int dp[M][M][T], d[T];
int n, m;
int used[M][M][T];

int solve(int i, int j, int t){
	if(t == n){
		return 0;
	}

	int &ans = dp[i][j][t];

	if(used[i][j][t])
		return ans;

	used[i][j][t] = 1;

	ans = solve(i, j, t + 1);

	if(i - d[t] >= 0){
		ans = max(ans,1 + solve(i - d[t], j, t + 1));
	}

	if(j - d[t] >= 0){
		ans = max(ans, 1 + solve(i, j - d[t], t + 1));
	}

	return ans;

}

set<int> ladoa, ladob;
void guga(int i, int j, int t) {
	if(t == n){
		return;
	}

	int ans1 = dp[i][j][t+1], ans2 = -1, ans3 = -1;

	if(i - d[t] >= 0){
		ans2 = 1 + dp[i -d[t]][j][t+1];
	}

	if(j - d[t] >= 0){
		ans3 = 1 + dp[i][j - d[t]][t+1];
	}

	int ans = dp[i][j][t];

	if (ans == ans1)
		guga(i, j, t+1);	
	else if (ans == ans2) {
		ladoa.insert(t+1);
		guga(i - d[t], j, t+1);
	}
	else if (ans == ans3) {
		ladob.insert(t+1);
		guga(i, j - d[t], t+1);
	}
} 

int main (){
	cin >> m >> n;

	for(int i = 0 ; i < n ; i++){
		cin >> d[i];
	}

	cout << solve(m, m, 0) << endl;

	guga(m, m, 0);

	cout << "Lado A: ";
	for (auto it = ladoa.begin(); it != ladoa.end(); it++)
		cout << *it << " \n"[it == prev(ladoa.end())];


	cout << "Lado B: ";
	for (auto it = ladob.begin(); it != ladob.end(); it++)
		cout << *it << " \n"[it == prev(ladob.end())];

	return 0;
}