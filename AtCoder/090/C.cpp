#include <bits/stdc++.h>
using namespace std;

int n;
const int M = 110;
const int N = 2;
int grid[N][M];

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int I[] = {+1, +0};
const int J[] = {+0, +1};

bool vis[N][M];

//int run(int i, int j) {
//    priority_queue<iii> q;
//
//    q.push(iii(grid[i][j], ii(i, j)));
//
//    int ans = 0;
//
//    while (!q.empty()) {
//        auto t = q.top();
//        i = t.second.first;
//        j = t.second.second;
//        q.pop();
//
//        if (vis[i][j])
//            continue;
//        vis[i][j] = true;
//
//        if (i == N-1 && j == n-1) {
//            ans = t.first;
//        }
//
//        for (int k = 0; k < 4; k++) {
//            int di = i + I[k];
//            int dj = j + J[k];
//
//            if (0 <= di && di < N && 0 <= dj && dj < n) {
//                q.push(iii(t.first + grid[di][dj], ii(di, dj)));
//            }
//        }
//    }
//
//    return ans;
//}

int run(int i, int j, int candies) {
    if (i == N-1 && j == n-1)
        return candies;

    if (i == N-1)
        return run(i, j+1, candies + grid[i][j+1]);
    else if (j == n-1)
        return run(i+1, j, candies + grid[i+1][j]);
    else
        return max(run(i, j+1, candies + grid[i][j+1]),
                run(i+1, j, candies + grid[i+1][j]));
}

int main() {
    cin >> n;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << run(0,0, grid[0][0]) << endl;
    return 0;
}
