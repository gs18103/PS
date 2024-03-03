#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;  

const int MAX = 353030;
const int INF = 1e9;
const ll LINF = 1e18;

struct TRI {
    int a, b, c;
    TRI(int x, int y, int z) {
        a = x, b = y, c = z;
    }
};

bool dp[MAX][3], flag; // 0: 분해 가능 / 1: 루트 위에 하나 필요 / 2: 루트만 남음
int cnt[MAX][3];
vector <int> g[MAX];
vector <TRI> ans;

inline void dfs(int x, int pa) {
    int k1 = 0, k2 = 0;
    for(int i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
        if(dp[i][0]) cnt[x][0]++;
        if(dp[i][1]) cnt[x][1]++;
        if(dp[i][2]) {
            cnt[x][2]++;
            if(k1 == 0) k1 = i;
            else k2 = i;
        }
    }
    if(cnt[x][1] == 0 && cnt[x][2] == 2) dp[x][0] = true, ans.eb(x, k1, k2);
    else if(cnt[x][1] == 1 && cnt[x][2] == 0) dp[x][0] = true;
    else if(cnt[x][1] == 0 && cnt[x][2] == 1) dp[x][1] = true, ans.eb(x, k1, pa);
    else if(cnt[x][1] == 0 && cnt[x][2] == 0) dp[x][2] = true;
    else flag = true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    dfs(1, 0);
    
    if(flag) cout << "U";
    else {
        cout << "S\n";
        for(auto i : ans) {
            cout << i.a << ' ' << i.b << ' ' << i.c << '\n';
        }
    }
}