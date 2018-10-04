// UVA - 10258 - Contest Scoreboard
#include <bits/stdc++.h>
using namespace std;

struct contestant {
    int id;
    int prob_mask; // bitmask for accepted problems
    int cs; // correct submissions
    int pen; // penalties
    
    bool operator<(const contestant &other) {
        return this->cs > other.cs ||
            (this->cs == other.cs && this->pen < other.pen) ||
            (this->cs == other.cs && this->pen == other.pen && this->id < other.id);
    }
};

int main() {
    const int C = 110, P = 15;
    int64_t penalty[C][P];
    contestant contestants[C];
    int t;
    int con, prob, time;
    char type;
    string line;

    cin >> t;
    cin.get();
    cin.get();

    while (t--) {
        memset(penalty, 0, sizeof(penalty));
        memset(contestants, 0, sizeof(contestants));

        while (getline(cin, line) && !line.empty()) {
            istringstream iss(line);
            iss >> con >> prob >> time >> type;

            contestants[con].id = con; 

            switch (type) {
                case 'C':
                    if (!(contestants[con].prob_mask & (1 << prob))) {
                        contestants[con].prob_mask |= (1 << prob);
                        contestants[con].cs = __builtin_popcount(contestants[con].prob_mask);
                        contestants[con].pen += 20 * penalty[con][prob] + time;
                    }
                    break;
                case 'I':
                    penalty[con][prob]++;
                    break;
            }
        }

        sort(contestants, contestants+C);

        for (int i = 0; i < C; i++) {
            if (contestants[i].id > 0) {
                cout << contestants[i].id << " " << contestants[i].cs
                    << " " << contestants[i].pen << "\n";
            }
        }

        if (t > 0)
            cout << "\n";
    }
    return 0;
}
