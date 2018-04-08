//Spoj - Tic-Tac-Toe I - TOE1
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vii;

bool gameover(string state) {
    for (auto i : {0, 1, 2}) {
        if (state[i] != '.' && state[i] == state[i+3]
                && state[i+3] == state[i+6])
            return true;
    }

    for (auto i : {0, 3, 6}) {
        if (state[i] != '.' && state[i] == state[i+1]
                && state[i+1] == state[i+2])
            return true;
    }

    for (auto idxs : vector<vii>{ {0, 4, 8}, {2, 4, 6} }) {
        if (state[idxs[0]] != '.' && state[idxs[0]] == state[idxs[1]]
                && state[idxs[1]] == state[idxs[2]])
            return true;
    }

    return false;
}

bool dfs(string state, bool turn, string &finalstate) {
    if (state == finalstate)
        return true;

    if (gameover(state))
        return false;

    int i = 0;
    for (auto &c : state) {
        if (c == '.') {
            c = turn ? 'X' : 'O';
            if (c == finalstate[i])
                if (dfs(state, !turn, finalstate))
                    return true;
            c = '.';
        }

        i++;
    }

    return false;
}

int main() {
    int n;
    char ch;
    string game;

    cin >> n;
    while (n--) {
        game = "";
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> ch, game += ch;

        cout << (dfs(string(9, '.'), true, game) ? "yes" : "no") << endl;
    }
}
