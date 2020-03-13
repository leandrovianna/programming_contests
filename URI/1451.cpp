// URI - Teclado Quebrado - 1451
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    
    while (cin >> line) {
        list<char> buffer;
        
        auto it = buffer.begin();
        
        for (const auto &ch : line) {
            if (ch == '[')
                it = buffer.begin();
            else if (ch == ']')
                it = buffer.end();
            else  
                buffer.insert(it, ch);
        }
        
        for (const auto &ch : buffer) {
            cout << ch;
        }
        cout << "\n";
    }    
    return 0;
}
