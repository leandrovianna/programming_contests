#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

typedef short i16;
typedef long i32;
typedef long long i64;

#define N 110
#define M 110

/* Cartesian Plane based in sparse matrix */

#define P (N*N)

typedef struct {
	int x, y;
	int v;
} Point;

typedef struct {
	Point points[P];
	size_t size;
} Plane;

Plane* Plane_new() {
	Plane *p = (Plane*) malloc(sizeof(Plane));
	p->size = 0;
	return p;
}

void Plane_set_point(Plane *p, int x, int y, int v) {
	for (int i = 0; i < p->size; i++) {
		if (p->points[i].x == x && p->points[i].y == y) {
			p->points[i].v = v;
			return;
		}
	}

	Point pt = {x, y, v};
	p->points[p->size] = pt;
	p->size++;
}

int Plane_get_point(Plane *p, int x, int y) {
	for (int i = 0; i < p->size; i++) {
		if (p->points[i].x == x && p->points[i].y == y) 
			return p->points[i].v;
	}

	return 0;
}

void Plane_reset(Plane *p) {
	p->size = 0;
}

void Plane_print(Plane *p, int n, int m) {
	for (int j = 0; j <= m; j++) {
		for (int i = 0; i <= n; i++) {
			cout << Plane_get_point(p, i, j);
			if (i != n) cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}
/* end */

int dist[N][N];
pair<int, int> pred[N][N];
const int W = 1;
const int I[] = {0, -1, 0, 1};
const int J[] = {-1, 0, 1, 0};

void bfs(Plane *p, int si, int sj, const int n, const int m) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dist[i][j] = -1;
			pred[i][j] = make_pair(-1, -1);
		}
	}
	
	int vi, vj, ni, nj;

	queue<pair<int, int> > q;
	q.push(make_pair(si, sj));
	dist[si][sj] = 0;

	while (!q.empty()) {
		vi = q.front().first;
		vj = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			ni = vi + I[i];
			nj = vj + J[i];

			if ((0 <= ni && ni <= n) && (0 <= nj && nj <= m)
					&& !Plane_get_point(p, ni, nj) && dist[ni][nj] == -1) {
				q.push(make_pair(ni, nj));
				dist[ni][nj] = dist[vi][vj] + W;
				pred[ni][nj] = make_pair(vi, vj);
			}
		}
	}

}

void mark_shortest_route(Plane *p, int di, int dj, int v) {
	int x, y;
	pair<int, int> tmp;
	x = di;
	y = dj;
	while (pred[x][y].first != -1) {
		Plane_set_point(p, x, y, v);
		tmp = pred[x][y];
		x = tmp.first;
		y = tmp.second;
	}

}

int minc(int a, int b) {
	if (a < 0) return b;
	if (b < 0) return a;
	return (a < b) ? a : b;
}

int main() {
	int a1x, a1y, a2x, a2y,
		b1x, b1y, b2x, b2y;

	Plane *p = Plane_new();
	int n, m, d1, d2;
	pair<int, int> tmp;

	cin >> n >> m;

	cin >> a1x >> a1y;
	cin >> a2x >> a2y;
	cin >> b1x >> b1y;
	cin >> b2x >> b2y;

	// first attempt
	Plane_set_point(p, a1x, a1y, 1);
	Plane_set_point(p, b1x, b1y, 1);
	Plane_set_point(p, b2x, b2y, 1);
	//dont mark a2 cause bfs should reach it

	bfs(p, a1x, a1y, n, m);
	d1 = dist[a2x][a2y];
	mark_shortest_route(p, a2x, a2y, 2);

	// unmark b2 cause bfs should reach it
	Plane_set_point(p, b2x, b2y, 0);
	bfs(p, b1x, b1y, n, m);
	if (dist[b2x][b2y] == -1) d1 = -1;
	else d1 += dist[b2x][b2y];

	Plane_reset(p);

	// second attempt
	Plane_set_point(p, a1x, a1y, 1);
	Plane_set_point(p, a2x, a2y, 1);
	Plane_set_point(p, b1x, b1y, 1);
	//dont mark b2 cause bfs should reach it

	bfs(p, b1x, b1y, n, m);
	d2 = dist[b2x][b2y];
	mark_shortest_route(p, b2x, b2y, 2);

	// unmark a2 cause bfs should reach it
	Plane_set_point(p, a2x, a2y, 0);
	bfs(p, a1x, a1y, n, m);
	if (dist[a2x][a2y] == -1) d2 = -1;
	else d2 += dist[a2x][a2y];

	// bfs a1
	// save distance between a1 and a2
	// bfs b1 (with path between a1 and a2 marked)
	// save distance between b1 and b2
	//
	// unmarked points
	// bfs b1
	// save distance between b1 and b2
	// mark path between b1 and b2
	// bfs a1
	// save distance between a1 and a2
	
	// now, choose the shortest cost
	
	if (d1 == -1 && d2 == -1)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << minc(d1, d2) << endl;

	return 0;
}
