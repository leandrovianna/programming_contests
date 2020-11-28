// UVa - DNA Sequencing - 760
#include <bits/stdc++.h>
using namespace std;

// lexicographic order for pairs
inline bool leq(int a1, int a2, int b1, int b2) {
    return a1 < b1 || (a1 == b1 && a2 <= b2);
}

// and triples
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
    return a1 < b1 || (a1 == b1 && leq(a2,a3, b2,b3));
} // and triples

// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
static void radixPass(int* a, int* b, int* r, int n, int K) {// count occurrences
    int* c = new int[K + 1]; // counter array
    for (int i = 0; i <= K; i++) c[i] = 0; // reset counters
    for (int i = 0; i < n; i++) c[r[a[i]]]++; // count occurrences
    for (int i = 0, sum = 0; i <= K; i++) // exclusive prefix sums
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (int i = 0;  i < n; i++) b[c[r[a[i]]]++] = a[i]; // sort
    delete [] c;
}

// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void suffixArray(int* s, int* SA, int n, int K) {
    s[n] = s[n+1] = s[n+2] = 0;

    int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2;
    int* s12 = new int[n02+3]; s12[n02] = s12[n02+1] = s12[n02+2] = 0;
    int* SA12 = new int[n02+3]; SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
    int* s0 = new int[n0];
    int* SA0 = new int[n0];
    // generate positions of mod 1 and mod 2 suffixes
    // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
    for (int i=0, j=0; i < n + (n0-n1); i++)
        if (i%3 != 0) s12[j++] = i;
    // lsb radix sort the mod 1 and mod 2 triples
    radixPass(s12 , SA12, s+2, n02, K);
    radixPass(SA12, s12 , s+1, n02, K);
    radixPass(s12 , SA12, s  , n02, K);
    // find lexicographic names of triples
    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n02; i++) {
        if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) {
            name++;
            c0 = s[SA12[i]];
            c1 = s[SA12[i]+1];
            c2 = s[SA12[i]+2];
        }
        if (SA12[i]%3 == 1) s12[SA12[i]/3] = name; // left half
        else s12[SA12[i]/3 + n0] = name; // right half
    }
    // recurse if names are not yet unique
    if (name < n02) {
        suffixArray(s12, SA12, n02, name);
        // store unique names in s12 using the suffix array
        for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
    } else // generate the suffix array of s12 directly
        for (int i = 0;  i < n02; i++) SA12[s12[i] - 1] = i;
    // stably sort the mod 0 suffixes from SA12 by their first character
    for (int i = 0, j = 0; i < n02; i++)
        if (SA12[i] < n0) s0[j++] = 3*SA12[i];
    radixPass(s0, SA0, s, n0, K);
    // merge sorted SA0 suffixes and sorted SA12 suffixes
    for (int p = 0, t = n0-n1, k = 0; k < n; k++) {
        #define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
        int i = GetI(); // pos of current offset 12 suffix
        int j = SA0[p]; // pos of current offset 0 suffix
        if (SA12[t] < n0 ? // different compares for mod 1 and mod 2 suffixes
            leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) :
            leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0]))
        {// suffix from SA12 is smaller
            SA[k] = i; t++;
            if (t == n02) // done --- only SA0 suffixes left
            for (k++; p < n0; p++, k++) SA[k] = SA0[p];
        } else {// suffix from SA0 is smaller
            SA[k] = j; p++;
            if (p == n0) // done --- only SA12 suffixes left
            for (k++; t < n02; t++, k++) SA[k] = GetI();
        }
    }
    delete [] s12; delete [] SA12; delete [] SA0; delete [] s0;
}

const int N = 2*610, E = 260;
const int K = 20;
int lg[N+1];
int st[N][K+1];

void lcp_construction(int *s, int n, int *sa, int *rnk, int *lcp) {
	for (int i = 0; i < n; i++) {
		rnk[sa[i]] = i;
	}

	int k = 0;
	for (int i = 0; i < n-1; i++) {
		lcp[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		if (rnk[i] == n - 1) {
			k = 0;
			continue;
		}

		int j = sa[rnk[i] + 1];
    while (i + k < n && j + k < n && s[i+k] == s[j+k]) {
			k++;
    }
		lcp[rnk[i]] = k;
		if (k) k--;
	}

  lg[1] = 0;
  for (int i = 2; i <= N; i++)
    lg[i] = lg[i/2] + 1;

  for (int i = 0; i < n-1; i++)
    st[i][0] = lcp[i];

  for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= n-1; i++)
      st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int lcp_query(int l, int r) {
  assert(l <= r);
  int j = lg[r - l + 1];
  return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int basestr[N], sa[N], rnk[N], lcp[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<string> inputs;
  string s1, s2;

  while (getline(cin, s1)) {
    inputs.push_back(s1);
  }

  for (int i = 0, m = inputs.size(); i < m; i += 3) {
    s1 = inputs[i];
    s2 = inputs[i+1];

    int sz = 0;
    for (const auto &ch : s1) {
      basestr[sz++] = ch;
    }
    int division = sz;
    basestr[sz++] = '$';
    for (const auto &ch : s2) {
      basestr[sz++] = ch;
    }

    suffixArray(basestr, sa, sz, E);
    lcp_construction(basestr, sz, sa, rnk, lcp);

    set<string> seqs;
    int lcs_size = 0;
    for (int i = 0; i < sz-1; i++) {
      if (lcp[i] == 0 || (sa[i] < division) == (sa[i+1] < division))
        continue;

      if (lcp[i] >= lcs_size) {
        if (lcp[i] > lcs_size)
          seqs.clear();

        lcs_size = lcp[i];
        string t = "";
        for (int j = 0; j < lcs_size; j++) {
          t += basestr[sa[i] + j];
        }
        seqs.insert(t);
      }
    }

    if (seqs.size() == 0) {
      cout << "No common sequence.\n";
    } else {
      for (const auto &s : seqs) {
        cout << s << "\n";
      }
    }

    if (i+1 < m-1)
      cout << "\n";
  }
  return 0;
}
