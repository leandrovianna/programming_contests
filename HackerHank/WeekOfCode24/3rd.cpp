#include <iostream>
#include <map>
using namespace std;

int piece(char t) {
	switch (t) {
		case 'Q': return 1;
		case 'N': return 2;
		case 'B': return 3;
		case 'R': return 4;
		default: return -1;
	}
}

struct place {
	char t;
	char c;
	int r;
};

int main() {
	int g, w, b, m, r;
	char t, c;
	place tab[16];
	
	cin >> g;
	for (int gi = 0; gi < g; gi++) {
		cin >> w >> b >> m;
		int i = 0;
		for (int wi = 0; wi < w; wi++) {
			cin >> tab[i].t >> tab[i].c >> tab[i].r;
			i++;
		}
		for (int bi = 0; bi < b; bi++) {
			cin >> tab[i].t >> tab[i].c >> tab[i].r;
			i++;
		}
	}
	return 0;
}
