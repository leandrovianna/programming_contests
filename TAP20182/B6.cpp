// TAP 2018/2 - Volleyball Scoring B6
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char ch;
    int points[2] = {0, 0};
    bool serve = false; // false indicate service with team A

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ch;
        bool won = (ch == 'B');

        if (won == serve) {
            points[won]++;
        } else {
            serve = won;
        }

        if (points[won] >= 15 && points[won] - points[!won] >= 2) {
            cout << "Team " << (won ? "B" : "A") << " has won the "
                << "match with a score of " << points[0] << "-" 
                << points[1] << "." << endl;
            return 0;
        }
    }

    cout << "The score is " << points[0] << "-" << points[1] 
        << "." << endl;

    return 0;
}
