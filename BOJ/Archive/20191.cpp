#include <bits/stdc++.h>

using namespace std;

vector <int> pos[26];

int main() {
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    for(int i = 0; i < t.size(); i++) {
        pos[t[i]-'a'].emplace_back(i);
    }
    int cnt = 1, cur = 0;
    for(int i = 0; i < s.size(); i++) {
        if(cur == t.size()) {
            cnt++;
            cur = 0;
        }
        int ncur = lower_bound(pos[s[i]-'a'].begin(), pos[s[i]-'a'].end(), cur) - pos[s[i]-'a'].begin();
        if(ncur == pos[s[i]-'a'].size()) {
            ncur = lower_bound(pos[s[i]-'a'].begin(), pos[s[i]-'a'].end(), 0) - pos[s[i]-'a'].begin();
            if(ncur == pos[s[i]-'a'].size()) {
                cout << -1 << endl;
                return 0;
            }
            cnt++;
        }
        cur = pos[s[i]-'a'][ncur] + 1;
    }
    
    cout << cnt << endl;

    return 0;
}