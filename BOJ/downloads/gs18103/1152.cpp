#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    bool flag = false;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') flag = true;
        if(i == 0 && s[i] != ' ') cnt++;
        if(i > 0 && s[i-1] == ' ') cnt++;
    }
    cout << cnt << endl;
}