//CodeChef SUMTRIAN
#include <iostream>
using namespace std;
const int N = 300;
int main() {
	ios::sync_with_stdio(false);
	int t, n, x, value[N][N];
	cin >> t;
	while (t-- > 0) {
		cin >> n;
		cin >> value[0][0];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin>>x;
				value[i][j]=((j==0)?value[i-1][j]:max(value[i-1][j-1],value[i-1][j]))+x;
			}
		}
		int r = 0;
		for (int i = 0; i < n; i++)
			r = max(r, value[n-1][i]);
		cout << r << endl;
	}
	return 0;
}
