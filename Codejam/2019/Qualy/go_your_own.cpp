// Codejam 2019 - Qualification Round - You Can Go Your own way
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    string moves;
    
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> n >> moves;

        for (size_t i = 0; i < moves.size(); i++) {
            moves[i] = (moves[i] == 'E' ? 'S' : 'E');
        }

        cout << "Case #" << ti << ": " << moves << "\n";
    }

    return 0;
}
