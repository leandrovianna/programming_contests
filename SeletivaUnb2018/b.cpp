#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
char t[N][N];
int mark[N][N];
int vi[4] = {-1, 1}, vj[4] = {-1, 1};

int main(){
	int n, m;

	cin >> n >> m;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> t[i][j];
		}
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(t[i][j] != 'N' || mark[i][j])
				continue;
			mark[i][j] = true;

			int k = i + 1;
			bool vertical = false;
			bool horizontal = false;

			while(k < n && t[k][j] == 'N'){
				if(mark[k][j]){
					cout << "Reorganize o tabuleiro" << endl;
					return 0;
				}
				if(j - 1 >= 0){
					if(t[k][j - 1] == 'N'){
						cout << "Reorganize o tabuleiro" << endl;
						return 0;
					}
				}				

				if(j + 1 < m){
					if(t[k][j + 1] == 'N'){	
						cout << "Reorganize o tabuleiro" << endl;
						return 0;
					}
				}

				vertical = true;
				mark[k][j] = true;
				k++;
			}

			k = j + 1;

			while(k < m && t[i][k] == 'N'){
				if(vertical || mark[i][k]){
					cout << "Reorganize o tabuleiro" << endl;
					return 0;
				}

				if(i - 1 >= 0){
					if(t[i - 1][k] == 'N'){
						cout << "Reorganize o tabuleiro" << endl;
						return 0;
					}
				}

				if(i + 1 < n){
					if(t[i + 1][k] == 'N'){
						cout << "Reorganize o tabuleiro" << endl;
						return 0;
					}
				}

				horizontal = true;
				mark[i][k] = true;
				k++;
			}

			if(i + 1 < n && j + 1 < m){
				if(t[i + 1][j + 1] == 'N'){
					cout << "Reorganize o tabuleiro" << endl;
					return 0;
				}
			}

			if(i - 1 >= 0 && j + 1 < m){
				if(t[i - 1][j + 1] == 'N'){
					cout << "Reorganize o tabuleiro" << endl;
					return 0;
				}
			}

			if(i + 1 < n && j - 1 >= 0){
				if(t[i + 1][j - 1] == 'N'){
					cout << "Reorganize o tabuleiro" << endl;
					return 0;
				}
			}

			if(i - 1 >= 0 && j - 1 >= 0){
				if(t[i - 1][j - 1] == 'N'){
					cout << "Reorganize o tabuleiro" << endl;
					return 0;
				}
			}
		}
	}

	cout << "Comece a partida" << endl;

	return 0;
}