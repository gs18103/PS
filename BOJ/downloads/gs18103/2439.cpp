#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s, t;
    for(int i = 0; i < n; i++) s += ' ';

    for(int i = 1; i <= n; i++) {
        s.pop_back();
        t += '*';
        cout << s << t << '\n';
    }
}