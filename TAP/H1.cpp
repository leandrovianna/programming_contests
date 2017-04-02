#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
	int x, y;
} Tree;

//Path equation x = a or y = a
//example: x = 1
//Path{true, 1}
typedef struct {
	bool is_x;
	int a;
} Path;

#define N 100000
#define M N

#define MAX(x,y) ((x > y) ? x : y)
#define MIN(x,y) ((x < y) ? x : y)

int main() {
	int t, n, m, qtd;
	Tree trees[N], *a, *b;
	Path paths[M], *p;
	char s[5];
	bool obstruction, can_view[N];

	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		cin >> n >> m;

		memset(can_view, 0, sizeof(can_view));

		for (int ni = 0; ni < n; ni++)
			cin >> trees[ni].x >> trees[ni].y;

		for (int mi = 0; mi < m; mi++) {
			cin >> s;
			paths[mi].is_x = (s[0] == 'x');
			paths[mi].a = s[2] == '-' ? -(s[3] - '0') : s[2] - '0';
		}

		for (int i = 0; i < n; i++) {
			a = &trees[i];

			for (int j = 0; j < m; j++) {
				p = &paths[j];
				obstruction = false;

				for (int k = 0; k < n; k++) {
					b = &trees[k];

					if (p->is_x) {
						if (b->y == a->y 
								&& MIN(a->x, p->a) < b->x
								&& b->x < MAX(a->x, p->a)) {
							obstruction = true;
							break;
						}
					} else {
						
						if (b->x == a->x
							&& MIN(a->y,p->a) < b->y
							&& b->y < MAX(a->y,p->a)) {
							obstruction = true;
							break;
						}
					}
				}

				if (!obstruction) {
					can_view[i] = true;
					break;
				}

			}
		}

		qtd = 0;
		for (int i = 0; i < n; i++) 
			if (can_view[i])
				qtd++;

		cout << qtd << endl;
	}
	return 0;
}
