// Spoj - Substring Problem - SUB_PROB - TLE
#include <bits/stdc++.h>
using namespace std;
const int M = 100100; // length of string
const int N = 2*M, E = 26+26+10+5;

struct SuffixAutomaton {
  int edges[N][E];
  int link[N];
  int length[N];
  bool term[N];
  int last, sz;
  int states;

  int code(char ch) {
    if ('0' <= ch && ch <= '9')
      return ch - '0';

    if ('a' <= ch && ch <= 'z')
      return ch - 'a' + 10;

    if ('A' <= ch && ch <= 'Z')
      return ch - 'A' + 10 + 26;

    throw runtime_error("Character not supported");
  }

  void init() {
    memset(edges, -1, sizeof(edges));
    // add the initial node
    states = 1;
    link[0] = -1;
    length[0] = 0;
    term[0] = false;
    last = 0; // initiate with index of first state
    sz = 0; // length of longest suffix added to automaton
  }

  void from(string s) {
    init();
    for (const auto &ch : s) {
      extend(ch);
    }
    find_terminals();
  }

  void extend(char ch) {
    // create new state for new equivalence (end-points) class
    sz++;
    length[states] = sz;
    link[states] = 0;
    term[states] = false;
    states++;

    int r = states - 1;
    int p = last;

    while (p >= 0 && edges[p][code(ch)] == -1) {
      edges[p][code(ch)] = r;
      p = link[p];
    }

    if (p != -1) {
      int q = edges[p][code(ch)];
      if (length[p] + 1 == length[q]) {
        link[r] = q;
      } else {
        for (int e = 0; e < E; e++) {
          edges[states][e] = edges[q][e];
        }
        length[states] = length[p] + 1;
        link[states] = link[q];
        term[states] = false;
        states++;

        int qq = states - 1;
        link[q] = qq;
        link[r] = qq;

        while (p >= 0 && edges[p][code(ch)] == q) {
          edges[p][code(ch)] = qq;
          p = link[p];
        }
      }
    }

    last = r;
  }

  void find_terminals() {
    memset(term, 0, sizeof(term));
    int p = last;
    while (p >= 0) {
      term[p] = true;
      p = link[p];
    }
  }
};

#ifdef __WIN32__
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif

bool readChar(char &c) {
  c = getchar_unlocked();
  return c != EOF;
}

inline void writeChar(char c) {
  putchar_unlocked(c);
}

template<typename T>
bool readInt( T &n ) { 
  n = 0; 
  bool neg = false; 
  char c = getchar_unlocked(); 
  if( c == EOF) { n = -1; return false; } 
  while (!('0' <= c && c <= '9')) { 
    if( c == '-' ) neg = true; 
    c = getchar_unlocked(); 
  } 
  while ('0' <= c && c <= '9') { 
    n = n * 10 + c - '0'; 
    c = getchar_unlocked(); 
  } 
  n = (neg ? (-n) : (n)); 
  return true; 
} 

template<typename T>
inline void writeInt(T n){ 
  int idx = 20; 
  if( n < 0 ) putchar_unlocked('-'); 
  n = abs(n); 
  char out[21]; 
  out[20] = ' '; 
  do{ 
    idx--; 
    out[idx] = n % 10 + '0'; 
    n/= 10; 
  }while(n); 
  do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

string readString() {
  char ch;
  string s = "";
  // ignore white-spaces
  while (readChar(ch) && isspace(ch)) continue;
  if (ch == EOF) return s;
  do {
    s += ch;
  } while (readChar(ch) && !isspace(ch));
  return s;
}

void writeString(const string &s) {
  for (const auto &ch : s) {
    writeChar(ch);
  }
}

SuffixAutomaton sa;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  string s, p;

  s = readString();
  sa.from(s);

  readInt(n);

  for (int ni = 0; ni < n; ni++) {
    p = readString();
    bool isSubstring = true;

    int st = 0, nxt;
    for (const auto &ch : p) {
      nxt = sa.edges[st][sa.code(ch)];
      if (nxt == -1) {
        isSubstring = false;
        break;
      }

      st = nxt;
    }

    writeString(isSubstring ? "Y\n" : "N\n");
  }

  return 0;
}
