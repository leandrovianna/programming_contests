// AtCoder - Make Them Even - abc109D
#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int grid[N][N];
const int I[] = {+0, +0, -1, +1};
const int J[] = {-1, +1, +0, +0};
vector<pair<pair<int, int>, pair<int, int>>> output;

int main() {
    int h, w;

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w/2; j++) {
            if (grid[i][j] % 2) {
                output.push_back({{i, j}, {i, j+1}});
                grid[i][j+1]++;
                grid[i][j]--;
            }
            if (w % 2 == 0 && j == w/2-1)
                break;
            if (grid[i][w-j-1] % 2) {
                output.push_back({{i, w-j-1}, {i, w-j-2}});
                grid[i][w-j-2]++;
                grid[i][w-j-1]--;
            }
        }
    }

    for (int i = 0; i < h/2; i++) {
        if (grid[i][w/2] % 2) {
            output.push_back({{i, w/2}, {i+1, w/2}});
            grid[i+1][w/2]++;
            grid[i][w/2]--;
        }
        if (h % 2 == 0 && i == h/2-1)
            break;
        if (grid[h-i-1][w/2] % 2) {
            output.push_back({{h-i-1, w/2}, {h-i-2, w/2}});
            grid[h-i-2][w/2]++;
            grid[h-i-1][w/2]--;
        }
    }

    cout << output.size() << "\n";
    for (const auto &p : output) {
        cout << 1 + p.first.first << " "
            << 1 + p.first.second << " "
            << 1 + p.second.first << " "
            << 1 + p.second.second << "\n";
    }
    return 0;
}
