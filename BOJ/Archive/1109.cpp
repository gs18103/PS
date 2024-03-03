#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define reset(x) memset(x, 0, sizeof(x))
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 55;
const int INF = 1e9;
const ll LINF = 1e18;

string s[MAX];
bool chk[MAX][MAX], cchk[3030], bound[MAX][MAX];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int c[MAX][MAX], n, m;
int in[3030], dp[3030];

void dfs(int x, int y, int t) {
    if(chk[x][y]) return;
    c[x][y] = t;
    chk[x][y] = true;
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
        if(s[nx][ny] == 'x') dfs(nx, ny, t);
    }
}

vector <int> g[3030];

void bfs(int t) {
    reset(chk);
    queue <pii> q;
    for(int i = 1; i <= n; i++) {
        q.em(i, 1);
        q.em(i, m);
    }
    for(int i = 1; i <= m; i++) {
        q.em(1, i);
        q.em(n, i);
    }
    while(!q.empty()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();
        if(chk[x][y]) continue;
        chk[x][y] = true;
        if(c[x][y] == t) continue;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            q.em(nx, ny);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!chk[i][j] && c[i][j] != 0 && c[i][j] != t) g[c[i][j]].eb(t), in[t]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!chk[i][j] && s[i][j] == 'x') {
                cnt++;
                dfs(i, j, cnt);
            }
        }
    }
    if(cnt == 0) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!cchk[c[i][j]]) {
                cchk[c[i][j]] = true;
                bfs(c[i][j]);
            }
        }
    }

    queue <int> q;
    for(int i = 1; i <= cnt; i++) {
        if(in[i] == 0) q.em(i);
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto i : g[x]) {
            in[i]--;
            dp[i] = max(dp[i], dp[x] + 1);
            if(in[i] == 0) q.em(i);
        }
    }
    map <int, int> mp;
    for(int i = 1; i <= cnt; i++) {
        mp[dp[i]]++;
    }
    for(auto i : mp) cout << i.se << ' ';
}