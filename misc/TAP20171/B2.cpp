#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> separate_by_str(string s, string sep) {
	vector<string> v;
	size_t n = 0, old_n = 0;

	while ((n = s.find(sep, old_n)) != string::npos) {
		v.push_back(s.substr(old_n, n-old_n));
		old_n = n+1;
	}

	v.push_back(s.substr(old_n));
	return v;
}

int main() {
	string s;	
	size_t n;
	int happy = 0,
		sad = 0;

	getline(cin, s);

	n = 0;
	while ((n = s.find(":-)", n+1)) != string::npos) {
		happy++;
	}

	n = 0;
	while ((n = s.find(":-(", n+1)) != string::npos) {
		sad++;
	}

	if (happy + sad == 0) 
		cout << "none" << endl;
	else if (happy == sad)
		cout << "unsure" << endl;
	else if (happy > sad)
		cout << "happy" << endl;
	else
		cout << "sad" << endl;

	return 0;
}
