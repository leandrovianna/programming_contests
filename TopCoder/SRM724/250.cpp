#include <bits/stdc++.h>
using namespace std;

class GravityPuzzleEasy {
	public:
		vector <string> solve(vector <string> board) {
			vector<int> c(board[0].size());
			
			for (int i = 0; i < board[0].size(); i++) {
				c[i] = 0;
				for (int j = 0; j < board.size(); j++) {
					if (board[j][i] == '#')
						c[i]++;
				}
			}
			
			vector<string> ans;
			
			for (int i = 0; i < board[0].size(); i++) {
				for (int j = 0; j < board.size(); j++) {
					if (j < c[i]) board[j] += '.';
					else board[j] += '#';
				}
			}
			
			return ans;
		}
};;

int main() {
	ios::sync_with_stdio(false);
	
	return 0;
}
