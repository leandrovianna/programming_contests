//TopCoder - FiveRooksDiv2
#include <bits/stdc++.h>
using namespace std;

class FiveRooksDiv2 {
	public:
		int findMax(vector <string> board) {
			int ans = 0;
			for (int i = 0; i < board.size(); i++) {
				int count = 0;
				for (int j = 0; j < board[i].size(); j++) {
					if (board[i][j] == 'R')
						count++;
				}
				ans = max(ans, count);
			}
			for (int i = 0; i < board.size(); i++) {
				int count = 0;
				for (int j = 0; j < board[i].size(); j++) {
					if (board[j][i] == 'R')
						count++;
				}
				ans = max(ans, count);
			}

			return ans;
		}
};

int main() {
	ios::sync_with_stdio(false);

	
	return 0;
}
