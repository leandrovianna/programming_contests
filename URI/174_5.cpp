#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	long t, d;
} atend;


int main() {
	const int N = 1e4, T = N * 1e5;
	int c, n;
	atend a[N];
	priority_queue<long long> caixa;

	cin >> c >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].t >> a[i].d;
	}

	for (int i = 0; i < c; i++) {
		caixa.push(T);
	}

	int qtd = 0;
	for (int i = 0; i < n; i++) {
		long long x = caixa.top();
		caixa.pop();

		if (T - x - a[i].t > 20)
			qtd++;

		x -= a[i].d;
		caixa.push(x);
	}

	cout << qtd << endl;
	return 0;
}
