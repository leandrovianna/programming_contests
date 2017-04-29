#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool is_item_line(string s) {
	int n = 0;
	char c;
	for (size_t i = 0; i < s.size(); i++) {
		c = s[i];
		if (c == ':')
			n++;
	}

	return (n == 2);
}

void get_info(string s, int *qtd, double *price) {
	string sqtd, sprice;
	int n = 0;
	char c;

	for (size_t i = 0; i < s.size(); i++) {
		c = s[i];
		if (n == 1) {
			if (isdigit(c))
				sqtd += c;
		} else if (n == 2) {
			if (isdigit(c) || c == '.')
				sprice += c;
		}
			
		if (c == ':') {
			n++;
		}
	}

	try {
		*qtd = stoi(sqtd);
		*price = stod(sprice);
	} catch (...) {
	}
}

int main() {
	string s;	
	double total, price;
	int qtd;

	total = 0;
	while (getline(cin, s)) {
		if (is_item_line(s)) {
			get_info(s, &qtd, &price);
			total += qtd * price;
		}
	}

	cout << total << endl;
	return 0;
}
