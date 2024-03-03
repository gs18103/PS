#include <bits/stdc++.h>
#define eb emplace_back

using namespace std;

bool win(char a, char b) {
    if(a == 'R' && b == 'P') return true;
    if(a == 'P' && b == 'S') return true;
    if(a == 'S' && b == 'R') return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, T;
    cin >> n >> T;
    string s;
    cin >> s;
    
    list <char> v;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(v.size() > T) {
            cout << v.front();
            v.pop_front();
            if(cnt > T) cnt = T;
        }
        if(!v.empty() && win(s[i], v.back())) {
            while(v.size() > cnt) {
                cout << v.front();
                v.pop_front();
            }
            cout << s[i];
        }
        else {
            if(!v.empty() && v.back() == s[i]) cnt++;
            else cnt = 1;
            v.push_back(s[i]);
        }
    }
    while(!v.empty()) {
        cout << v.front();
        v.pop_front();
    }

    return 0;
}