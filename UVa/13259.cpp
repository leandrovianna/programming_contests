// UVa - Soccer Championship - 13259 
#include <bits/stdc++.h>
using namespace std;

const int N = 200;
int pos[N];
struct Team {
  string name;
  int idx;
  int points;
  int goalsDiff, goals, goalsAway;
  
  Team(string name = "", int idx = 0) 
    : name(name), idx(idx), points(0), goalsDiff(0), goals(0), goalsAway(0) {}

  bool operator<(const Team &other) {
    if (points > other.points)
      return true;
    else if (points == other.points) {
      if (goalsDiff > other.goalsDiff)
        return true;
      else if (goalsDiff == other.goalsDiff) {
        if (goals > other.goals)
          return true;
        else if (goals == other.goals) {
          if (goalsAway > other.goalsAway)
            return true;
          else if (goalsAway == other.goalsAway)
            return name < other.name;
        }
      }
    }

    return false;
  }
} teams[N];

const int M = 70;
struct Match {
  int index1, goals1;
  int index2, goals2;
} matches[M];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m;
  string local, visitor, line, token;

  while (cin >> m) {
    cin.ignore();
    map<string, int> idx;
    vector<string> tokens;

    for (int i = 0, x, y; i < m; i++) {
      getline(cin, line);
      istringstream iss(line);
      tokens.clear();
      while (iss >> token) {
        tokens.push_back(token);
      }

      for (int j = 0, sz = tokens.size(); j < sz; j++) {
        if (tokens[j] == "vs.") {
          local = tokens[0];
          for (int k = 1; k < j-1; k++)
            local += " " + tokens[k];
          x = stoi(tokens[j-1]);
          y = stoi(tokens[j+1]);
          visitor = tokens[j+2];
          for (int k = j+3; k < sz; k++)
            visitor += " " + tokens[k];
          break;
        }
      }

      // cout << local << " " << x << " " << y << " " << visitor << endl;

      if (idx.find(local) == idx.end()) {
        teams[idx.size()] = Team(local, idx.size());
        idx[local] = idx.size();
      }

      if (idx.find(visitor) == idx.end()) {
        teams[idx.size()] = Team(visitor, idx.size());
        idx[visitor] = idx.size();
      }

      int localIdx = idx[local], visitorIdx = idx[visitor];
      teams[localIdx].goals += x;
      teams[localIdx].goalsDiff += x;
      teams[localIdx].goalsDiff -= y;

      teams[visitorIdx].goals += y;
      teams[visitorIdx].goalsAway += y;
      teams[visitorIdx].goalsDiff += y;
      teams[visitorIdx].goalsDiff -= x;

      if (x > y) {
        teams[localIdx].points += 3;
      } else if (x < y) {
        teams[visitorIdx].points += 3;
      } else {
        teams[localIdx].points++;
        teams[visitorIdx].points++;
      }

      matches[i] = Match{localIdx, x, visitorIdx, y};
    }

    int n = idx.size();
    sort(teams, teams+n);

    for (int i = 0; i < n; i++) {
      pos[teams[i].idx] = i;
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
      auto &match = matches[i];

      if (match.goals1 == match.goals2)
        continue;

      int winner = (match.goals1 > match.goals2) 
        ? match.index1 : match.index2;
      int loser = (match.goals1 < match.goals2) 
        ? match.index1 : match.index2;

      if (pos[loser] < pos[winner])
        ans++;
    }

    cout << "The paradox occurs " << ans << " time(s).\n";

    for (int i = 1; i <= n; i++) {
      cout << i << ". " << teams[i-1].name << "\n";
    }
  }

  
  return 0;
}
