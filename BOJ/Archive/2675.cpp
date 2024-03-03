#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while(q--) {
        int x;
        string s;
        cin >> x >> s;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < x; j++) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}