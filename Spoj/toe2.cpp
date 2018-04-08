//Spoj - Tic-Tac-Toe (II) - TOE2
#include <bits/stdc++.h>
using namespace std;

bool gameover(string game) {
    int empty = count(game.begin(), game.end(), '.');

    if (empty == 0)
        return true;

    for (int i = 0; i < 9; i += 3) {
        if (game[i] != '.' && game[i] == game[i+1]
                && game[i+1] == game[i+2])
            return true;
    }

    for (int i = 0; i <= 2; i++) {
        if (game[i] != '.' && game[i] == game[i+3]
                && game[i+3] == game[i+6])
            return true;
    }

    for (auto idxs : vector<vector<int> >{ {0, 4, 8}, {2, 4, 6} }) {
        if (game[idxs[0]] != '.' && game[idxs[0]] == game[idxs[1]]
                && game[idxs[1]] == game[idxs[2]])
            return true;
    }

    return false;
}

bool bfs(string finalstate) {
    if (!gameover(finalstate)) {
        return false;
    }

    queue<pair<string, bool> > q;

    // pair (game_state, turn)
    // turn == true, first player turn

    q.push({string(9, '.'), true});

    while (!q.empty()) {
        string game = q.front().first;
        bool turn = q.front().second;
        q.pop();

        if (game == finalstate)
            return true;

        if (gameover(game))
            continue;

        string g;
        for (size_t i = 0; i < game.size(); i++) {
            if (game[i] == '.') {
                g = game;
                if (turn && finalstate[i] == 'X') {
                    g[i] = 'X';
                    q.push({g, false});
                } else if (!turn && finalstate[i] == 'O') {
                    g[i] = 'O';
                    q.push({g, true});
                }
            }
        }
    }

    return false;
}

int main() {
    string game;

    while (cin >> game && game != "end") {
        cout << (bfs(game) ? "valid" : "invalid") << endl;
    }
    return 0;
}
