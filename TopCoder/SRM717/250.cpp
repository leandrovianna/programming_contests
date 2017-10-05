#include <bits/stdc++.h>
using namespace std;

class NiceTable {
	public:
		string isNice(vector <string> t) {
			
			vector<int> x(t.size(), -1);
			vector<int> y(t[0].size(), -1);
			
			return bt(t, x, y, 0, 0) ? "Nice" : "Not nice";
		}
		
		bool bt(vector<string> t, vector<int> x, vector<int> y, int i, int j) {
			int ni = (j == t[i].size()-1 ? i+1 : i);
			int nj = (j == t[i].size()-1 ? 0 : j+1);
			
			cout << i << " " << j << endl;
			
			if (t[i][j] == '0') {
				if (x[i] == -1) {
					if (y[j] == -1) {
						x[i] = y[j] = 0;
				
						bool r = bt(t, x, y, ni, nj);
						
						x[i] = y[j] = 1;
						return r || bt(t, x, y, ni, nj);
						
					} else {
						x[i] = y[j];
						return bt(t, x, y, ni, nj);
					}
				} else if (y[j] == -1) {
					y[j] = x[i];
					return bt(t, x, y, ni, nj);
				} else {
					return x[i] == y[j];
				}
			}
			else if (t[i][j] == '1') {
				if (x[i] == -1) {
				
					
					if (y[j] == -1) {
						x[i] = 0;
						y[j] = 1;
					
						bool r = bt(t, x, y, ni, nj);
						
						x[i] = 1;
						y[j] = 0;
						return r || bt(t, x, y, ni, nj);
						
					} else {
						x[i] = !y[j];
						return bt(t, x, y, ni, nj);
					}
				} else if (y[j] == -1) {
					y[j] = !x[i];
					return bt(t, x, y, ni, nj);
				} else {
					return x[i] != y[j];
				}
			}
			
			return false;
		}
};
