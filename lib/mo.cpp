// Mo's Algorithm
// Problem H - Wine Production
#include <bits/stdc++.h>
using namespace std;

// Variables, that hold current "state" of computation
long long current_answer;

// Array to store answers (because the order we achieve them is messed up)
const int N = 100500;
long long answers[N];
int BLOCK_SIZE;
int arr[N];

// We will represent each query as three numbers: L, R, idx. Idx is 
// the position (in original order) of this query.
pair< pair<int, int>, int> queries[N];

unordered_map<int, int > cnt, caras;
map<int, int> ok;

// Essential part of Mo's algorithm: comparator, which we will
// use with std::sort. It is a function, which must return True
// if query x must come earlier than query y, and False otherwise.
inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y) {
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

// When adding a number, we first nullify it's effect on current
// answer, then update cnt array, then account for it's effect again.
inline void add(int pos) {
    cnt[arr[pos]]++;
    int q = cnt[arr[pos]];
    caras[q]++;

    if (caras[q] >= q) {
        ok[q]++;
    }
    if(!ok.empty()){
        current_answer = (*(ok.end()--)).first;
    }
    else current_answer = 1;
}

// Removing is much like adding.
inline void remove(int pos) {
    int q = cnt[arr[pos]];
    cnt[arr[pos]]--;
    caras[q]--;

    if (ok.count(q)){
        ok[q]--;
        if (ok[q] == 0) {
            ok.erase(q);
        }
    }
    if(!ok.empty()){
        current_answer = (*(ok.end()--)).first;
    }
    else current_answer = 1;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    BLOCK_SIZE = static_cast<int>(sqrt(n));

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < q; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].first.first--;
        queries[i].first.second--;
        
        queries[i].second = i;
    }

    // Sort queries using Mo's special comparator we defined.
    sort(queries, queries + q, mo_cmp);

    // Set up current segment [mo_left, mo_right].
    int mo_left = 0, mo_right = -1;

    for(int i = 0; i < q; i++) {
        // [left, right] is what query we must answer now.
        int left = queries[i].first.first;
        int right = queries[i].first.second;

        // Usual part of applying Mo's algorithm: moving mo_left
        // and mo_right.
        while(mo_right < right) {
            mo_right++;
            add(mo_right);
        }
        while(mo_right > right) {
            remove(mo_right);
            mo_right--;
        }

        while(mo_left < left) {
            remove(mo_left);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(mo_left);
        }

        // Store the answer into required position.
        answers[queries[i].second] = current_answer;
    }

    // We output answers *after* we process all queries.
    for(int i = 0; i < q; i++)
        cout << answers[i] << "\n";
    return 0;
}
