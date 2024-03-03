#include <bits/stdc++.h>

using namespace std;

char a[1010], b[1010];
int cnta[26], cntb[26];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> a >> b;
    int lena = strlen(a), lenb = strlen(b);
    for(int i = 0; i < lena; i++) {
        cnta[a[i]-'a']++;
    }
    for(int i = 0; i < lenb; i++) {
        cntb[b[i]-'a']++;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        ans += abs(cnta[i] - cntb[i]);
    }
    cout << ans;
}