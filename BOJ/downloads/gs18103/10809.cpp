#include <bits/stdc++.h>

using namespace std;

int p[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    for(int i = 0; i < 26; i++) {
        p[i] = -1;
    }
    for(int i = s.size() - 1; i >= 0; i--) {
        p[s[i]-'a'] = i;
    }
    for(int i = 0; i < 26; i++) {
        cout << p[i] << ' ';
    }
}