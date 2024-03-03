#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string s;
    while(getline(cin, s)) {
        int a = 0, b = 0, i = 0;
        for(; i < s.size(); i++) {
            if(s[i] == ' ') break;
            a = 10 * a + s[i] - '0';
        }
        i++;
        for(; i < s.size(); i++) {
            if(s[i] == ' ') break;
            b = 10 * b + s[i] - '0';
        }
        if(a == 0 && b == 0) break;
        cout << a + b << '\n';
    }
}