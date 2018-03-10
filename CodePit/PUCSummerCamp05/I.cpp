//Puc Summer Camp 2018
//Spoj - Deconding Morse Sequences - MORSE
#include <bits/stdc++.h>
using namespace std;

const int MAXNODES = 10010;
const int E = 2;
int trie[MAXNODES][E], cnt = 1;
int link[MAXNODES];
int fim[MAXNODES];
vector<string> dict;

void trie_add(string str, int id) {
	assert(id > 0);
	int node = 0;
	for (const auto &c : str) {
		int child = (c == '.') ? 1 : 0;
		if (trie[node][child]) {
			node = trie[node][child];
		} else {
			trie[node][child] = cnt;
			node = cnt;
			cnt++;
		}
	}

	fim[node] = id;
}

void aho()
{
    queue<int> q;
    q.push(0);
    int v, l;
    while(!q.empty())
    {
        v = q.front(); q.pop();
        l = link[v];
        fim[v] |= fim[l];
        for (int i = 0; i < E; ++i)
        {
            if(trie[v][i])
            {
                link[trie[v][i]] = v ? trie[l][i] : 0;
                q.push(trie[v][i]);
            }
            else
            {
                trie[v][i] = trie[l][i];
            }
        }
    }
}

map<char, string> MORSE;

string morse(string str) {
	string out = "";

	for (const auto &c : str) {
		out += MORSE[c];
	}

	return out;
}

const int N = 10010;
int dp[N][MAXNODES];
string code;

int solve(size_t i, int node) {
	if (i == code.size()) {
		return 1;
	}

	int &ans = dp[i][node];

	if (ans != -1)
		return ans;

	ans = 0;
	int local_node = node;
	for (size_t k = i; k < min(code.size(), i+1000); k++) {
		int child = (code[k] == '.') ? 1 : 0;
		local_node = trie[local_node][child];

		if (local_node == 0) break;

		if (fim[local_node]) {
			cout << i << " " << node << endl;
			cout << "match: " << dict[fim[local_node]-1] << endl;
			ans += solve(k+1, local_node);
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int d, n;
	string s;

	MORSE['A'] =  ".-";
	MORSE['B'] = "-...";
	MORSE['C'] = "-.-.";
	MORSE['D'] = "-..";
	MORSE['G'] = "--.";
	MORSE['K'] = "-.-";
	MORSE['O'] = "---";
	MORSE['S'] = "...";
	MORSE['W'] = ".--";
	MORSE['F'] = "..-.";
	MORSE['J'] = ".---";
	MORSE['N'] = "-.";
	MORSE['R'] = ".-.";
	MORSE['V'] = "...-";
	MORSE['Z'] = "--..";
	MORSE['E'] = ".";
	MORSE['I'] = "..";
	MORSE['M'] = "--";
	MORSE['Q'] = "--.-";
	MORSE['U'] = "..-";
	MORSE['Y'] = "-.--";
	MORSE['H'] = "....";
	MORSE['L'] = ".-..";
	MORSE['P'] = ".--.";
	MORSE['T'] = "-";
	MORSE['X'] = "-..-";

	cin >> d;
	while (d--) {
		cin >> code;
		cin >> n;

		memset(trie, 0, sizeof(trie));
		dict.clear();

		for (int i = 0; i < n; i++) {
			cin >> s;
			trie_add(morse(s), i+1);
			dict.push_back(s);
		}

		aho();

		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0) << endl;
	}

	return 0;
}
