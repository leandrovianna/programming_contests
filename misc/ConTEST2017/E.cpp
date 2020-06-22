#include <iostream>
#include <stack>
using namespace std;

enum {
	P1, P2
};

int main() {
	int t, x;
	char cod, num;
	stack<int> stack;
	string s;
	bool res;

	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cin >> s;	

		res = true;

		for (size_t i = 0; i < s.size(); i+=2) {
			cod = s[i];
			num = s[i+1];

			if (cod == 'P') {
				if (num == '1') stack.push(P1);
				else if (num == '2') stack.push(P2);
			}
			else if (cod == 'R') {
				if (stack.empty()) {
					res = false;
					break;
				}
				else {
					x = stack.top();
					stack.pop();

					if ((num == '1' && x == P1) 
							|| (num == '2' && x == P2)) {
						res = false;
						break;
					}
				}
			}
			
		}

		while (!stack.empty()) {
			stack.pop();
			res = false;
		}

		cout << "Caso " << ti << ": " << (res ? "Sim" : "Nao") << endl;
	}
	return 0;
}
