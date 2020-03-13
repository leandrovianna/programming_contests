#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string line;
    set<string> words;
    string word;
    
    while (cin >> line) {
        for (auto it = line.begin(); it != line.end(); it++) {
            if (!isalpha(*it))
                *it = ' ';
            else
                *it = tolower(*it);
        }
        
        istringstream iss(line);
        
        while (iss >> word) {
            words.insert(word);
        }  
    }    
     
    for (const auto &w : words) {
        cout << w << "\n";
    }
    return 0;
}
