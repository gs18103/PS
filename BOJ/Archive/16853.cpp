#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 303030;
const int INF = 1e9;
const ll LINF = 1e18;

int tobit(string s) {
    if(s == "RED") return 1;
    if(s == "GREEN") return 2;
    if(s == "BLUE") return 4;
    if(s == "YELLOW") return 3;
    if(s == "CYAN") return 6;
    if(s == "PURPLE") return 5;
    if(s == "WHITE") return 7;
    return 0;
}

vector <int> g[MAX], v;
int scc[MAX], ord[MAX], low[MAX], num, sz;
int n, m;

void dfs(int x) {
    v.eb(x);
    ord[x] = low[x] = ++num;
    for(int i : g[x]) {
        if(!ord[i]) {
            dfs(i);
            low[x] = min(low[x], low[i]);
        }
        else if(!scc[i]) {
            low[x] = min(low[x], ord[i]);
        }
    }
    
    if(low[x] == ord[x]) {
        sz++;
        while(!v.empty()) {
            scc[v.back()] = sz;
            v.pop_back();
            if(scc[x]) break;
        }
    }
}

void make_true(int x) {
    g[((x-1)^1)+1].eb(x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;
    bool flag = false;
    for(int i = 1; i <= m; i++) {
        int a, b; string k, c1, c2;
        cin >> a >> b >> k >> c1 >> c2;
        int C1 = tobit(c1), C2 = tobit(c2);
        if(C1 == 0) flag = true;
        if(k == "H") {
            for(int j = 0; j < 3; j++) {
                if(C1 >> j & 1) {
                    if(C2 >> j & 1) {
                        make_true(6*a-2*j-1);
                        make_true(6*b-2*j-1);
                    }
                    else {
                        g[6*a-2*j-1].eb(6*b-2*j);
                        g[6*b-2*j-1].eb(6*a-2*j);
                    }
                }
                else if(C2 >> j & 1) flag = true;
            }
        }
        else {
            for(int j = 0; j < 3; j++) {
                if(C1 >> j & 1) {
                    if(C2 >> j & 1) {
                        g[6*a-2*j].eb(6*b-2*j-1);
                        g[6*b-2*j].eb(6*a-2*j-1);
                    }
                    else {
                        make_true(6*a-2*j);
                        make_true(6*b-2*j);
                    }
                }
                else if(C2 >> j & 1) flag = true;
            }
        }
    }
    
    if(flag) {
        cout << "THINKINGFACE";
        return 0;
    }
    
    for(int i = 0; i <= 6 * n + 1; i++) {
        if(!ord[i]) dfs(i);
    }
    
    for(int i = 1; i <= 6 * n; i += 2) {
        if(scc[i] == scc[i+1]) {
            cout << "THINKINGFACE";
            return 0;
        }
    }
    cout << "ALIEN";
}