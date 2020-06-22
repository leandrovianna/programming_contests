//TAP20172 - Laboratorio de Biotecnologia - L5
#include <bits/stdc++.h>
using namespace std;

typedef complex < double > base;

void fft(vector < base > & a, bool invert) {
	int n = (int) a.size();
	if (n == 1) return;

	vector < base > a0(n / 2), a1(n / 2);
	for (int i = 0, j = 0; i < n; i += 2, ++j) {
		a0[j] = a[i];
		a1[j] = a[i + 1];
	}
	fft(a0, invert);
	fft(a1, invert);

	double ang = 2 * M_PI / n * (invert ? -1 : 1);
	base w(1), wn(cos(ang), sin(ang));
	for (int i = 0; i < n / 2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if (invert)
			a[i] /= 2, a[i + n / 2] /= 2;
		w *= wn;
	}
}

const int N = 1e5+10;

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	vector<base> pre(s.size());
	base acc = 0;
	int k = 0;
	for (auto &c : s) {
		pre[k] = acc + (base)(c - 'a');
		acc += pre[k];
		k++;
	}

	return 0;
}
