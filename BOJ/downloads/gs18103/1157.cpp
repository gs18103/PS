#include <bits/stdc++.h>

using namespace std;

int cnt[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'a') cnt[s[i]-'a']++;
        else cnt[s[i]-'A']++;
    }
    int mx = 0;
    for(int i = 0; i < 30; i++) {
        mx = max(mx, cnt[i]);
    }
    bool flag = false;
    for(int i = 0; i < 30; i++) {
        if(cnt[i] == mx) {
            if(flag) {
                cout << "?" << endl;
                return 0;
            }
            flag = true;
            s.clear();
            s += 'A' + i;
        }
    }
    cout << s << endl;
}