#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        int sum = 0, c = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'O') {
                c++;
                sum += c;
            }
            else c = 0;
        }
        cout << sum << '\n';
    }
}