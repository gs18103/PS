#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 1010;
const int INF = 1e9;
const ll LINF = 9e18;

vector <int> g[MAX];
bool chk[MAX];
int b[MAX];

bool dfs(int x) {
    chk[x] = true;
    for(int i : g[x]) {
        if(!b[i] || (!chk[b[i]] && dfs(b[i]))) {
            b[i] = x;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        g[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> g[i][j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        fill(chk + 1, chk + n + 1, false);
        if(dfs(i)) ans++;
    }
    cout << ans << endl;
}