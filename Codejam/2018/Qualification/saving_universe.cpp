// Codejam 2018 - Qualification - Saving The Universe Again
#include <bits/stdc++.h>
using namespace std;

const int N = 35;
int shot[N];
int damage(string p) {
    int beam = 1;
    int dam = 0;
    for (size_t i = 0; i < p.size(); i++) {
        shot[i] = beam;

        char c = p[i];
        if (c == 'C')
            beam *= 2;
        else if (c == 'S')
            dam += beam;
    }

    return dam;
}

int solve(int x, string& p) {
    int idx = 0; 
    for (size_t i = 1; i < p.size(); i++) {
        if (p[i] == 'S' && p[i-1] == 'C')
            idx = i;
    }

    int op = 0;
    while (x > 0) {
        x -= shot[idx] / 2;

        swap(p[idx], p[idx-1]); 

        shot[idx] /= 2;

        if (idx < (int)p.size()-1 && p[idx+1] == 'S') {
            idx = idx+1;
        } else {
            int i = idx-1;
            while (i >= 0 && p[i] == 'S') {
                i--;
            }
            idx = i+1;
        }

        op++;
    }
    
    return op;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, d;
    string p;

    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        cin >> d >> p;
        
        int x = damage(p) - d;

        if (x <= 0)
            cout << "Case #" << ti << ": 0\n";
        else {
            int shots = count(p.begin(), p.end(), 'S');
            if (shots > d)
                cout << "Case #" << ti << ": IMPOSSIBLE\n";
            else {
                cout << "Case #" << ti << ": " << solve(x, p) << "\n";
            }
        }
    }
    return 0;
}
