#include <bits/stdc++.h>

using namespace std;

char a[1010];
int cnta[26];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> a;
    int lena = strlen(a);
    for(int i = 0; i < lena; i++) {
        cnta[a[i]-'A']++;
    }
    int x = -1;
    for(int i = 0; i < 26; i++) {
        if(cnta[i] % 2 == 1) {
            if(x < 0) x = i;
            else {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
    }
    
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < cnta[i] / 2; j++) {
            cout << (char)('A' + i);
        }
    }
    if(x >= 0) cout << (char)('A'+x);
    for(int i = 25; i >= 0; i--) {
        for(int j = 0; j < cnta[i] / 2; j++) {
            cout << (char)('A' + i);
        }
    }
}