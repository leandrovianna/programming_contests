#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long i32;
typedef long long i64;

void gen_positions(int s, int pos[]) {
	int i = (s / 50) % 475;
	for (int j = 0; j < 25; j++) {
		i = (i * 96 + 42) % 475;
		pos[j] = 26 + i;
	}
}

int flag = 0;

bool suficient(int p, int pos[]) {
	int i;
	for (i = 0; i < 25; i++) {
		if (p == pos[i]) return true;
	}
	return false;
}

int main() {
	int p, x, y;

	cin >> p >> x >> y;

	int pos[25];
	gen_positions(x, pos);
	int z = x;
	i32 hacks = 0;
	while (!suficient(p, pos)) {
		z -= 50;
		if (z < y) break;
		gen_positions(z, pos);
	}

	int mods = 0;
	while (!suficient(p, pos)) {
		x += 50;
		mods++;
		gen_positions(x, pos);
	}

	hacks = ceil(mods / 2.0);
	cout << hacks << endl;
	return 0;
}
