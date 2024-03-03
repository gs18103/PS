#include <bits/stdc++.h>  
#define mod 2100000000  
  
using namespace std;  
  
string x[2][55];  
  
struct state {  
    int l, s;  
    string rem;  
    bool operator < (const state &t) const {  
        return make_tuple(l, s, rem) < make_tuple(t.l, t.s, t.rem);  
    }  
    bool operator == (const state &t) const {  
        return make_tuple(l, s, rem) == make_tuple(t.l, t.s, t.rem);  
    }  
};  
  
int n, k;  
map <state, int> dp;  
  
int f(state st) {  
    if(st.l + (int)st.rem.size() > k) return 0;  
    if(st.l + (int)st.rem.size() == k) {  
        bool flag = true;  
        for(int i = 0; i < st.rem.size()/2; i++) {  
            if(st.rem[i] != st.rem[st.rem.size()-1-i]) flag = false;  
        }  
        if(flag) return 1;  
        else return 0;  
    }  
    if(dp.find(st) != dp.end()) return dp[st];  
    if(st.s == 0) {  
        for(int i = 1; i <= n; i++) {  
            bool flag = true;  
            for(int j = 0; j < min(st.rem.size(), x[0][i].size()); j++) {  
                if(st.rem[j] != x[0][i][j]) flag = false;  
            }  
            if(flag) {  
                state tst;  
                tst.l = st.l + 2 * min(st.rem.size(), x[0][i].size());  
                tst.rem = "";  
                if(st.rem.size() < x[0][i].size()) {  
                    tst.s = 1;  
                    for(int j = st.rem.size(); j < x[0][i].size(); j++) {  
                        tst.rem += x[0][i][j];  
                    }  
                    dp[st] += f(tst);  
                    dp[st] %= mod;  
                }  
                else {  
                    tst.s = 0;  
                    for(int j = x[0][i].size(); j < st.rem.size(); j++) {  
                        tst.rem += st.rem[j];  
                    }  
                    dp[st] += f(tst);  
                    dp[st] %= mod;  
                }  
            }  
        }  
    }  
    else {  
        for(int i = 1; i <= n; i++) {  
            bool flag = true;  
            for(int j = 0; j < min(st.rem.size(), x[1][i].size()); j++) {  
                if(st.rem[j] != x[1][i][j]) flag = false;  
            }  
            if(flag) {  
                state tst;  
                tst.l = st.l + 2 * min(st.rem.size(), x[1][i].size());  
                tst.rem = "";  
                if(st.rem.size() <= x[1][i].size()) {  
                    tst.s = 0;  
                    for(int j = st.rem.size(); j < x[1][i].size(); j++) {  
                        tst.rem += x[1][i][j];  
                    }  
                    dp[st] += f(tst);  
                    dp[st] %= mod;  
                }  
                else {  
                    tst.s = 1;  
                    for(int j = x[1][i].size(); j < st.rem.size(); j++) {  
                        tst.rem += st.rem[j];  
                    }  
                    dp[st] += f(tst);  
                    dp[st] %= mod;  
                }  
            }  
        }         
    }  
    return dp[st];  
}  
  
int main() {  
    cin >> n >> k;  
    for(int i = 1; i <= n; i++) {  
        cin >> x[0][i];  
        x[1][i] = x[0][i];  
        reverse(x[1][i].begin(), x[1][i].end());  
    }  
    state st;  
    st.l = 0, st.s = 0, st.rem = "";  
    cout << f(st);  
} 