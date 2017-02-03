//Apanhando e Ganhando
//https://www.urionlinejudge.com.br/repository/UOJ_1084.html
//Accepted
#include <iostream>
#include <cstdio>
#include <list>
#include <iterator>
using namespace std;

#define N 100000

int main() {
	int n, d, a;
	char c;
	list<int> v;
	
	while (cin >> n >> d, n) {
		for (int i = 0; i < n; i++) {
			scanf("%c", &c);
			a = c - '0';
			if (a >= 0) {
				v.push_back(a);
			}
			else i--;
		}
	
		for (auto it = next(v.begin()); it != v.end(); it++) {
			if (d <= 0)
				break;

			if (*it > *prev(it)) {
				it = v.erase(prev(it));	
				if (it != v.begin())
					it--;
				d--;
			}
		}

		if (d > 0) 
			v.erase(prev(v.end(), d), v.end());

		for (const int &x : v)
			printf ("%d", x);
		printf ("\n");

		v.clear();
	}
	return 0;
}
