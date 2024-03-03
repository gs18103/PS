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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int arr[505][505], p[505][505], r[10];
int m[101010], t[101010];
pii pos[101010];
bool chk[505][505];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, h, w;
    cin >> n >> h >> w;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> arr[i][j];
            p[i][j] = -100;
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> r[i];
    }

    int M;
    cin >> M;
    for(int i = 1; i <= M; i++) {
        cin >> m[i] >> t[i] >> pos[i].fi >> pos[i].se;
        p[pos[i].fi][pos[i].se] = t[i];
    }

    int k;
    cin >> k;
    vector <pii> chked;
    while(k--) {
        int u, a, b;
        bool ans = false;
        cin >> u >> a >> b;
        if(p[a][b] != -100) continue;
        if(r[arr[a][b]] == -1) continue;

        p[pos[u].fi][pos[u].se] = -100;
        priority_queue <pair <int, pii> > pq;
        pq.em(m[u], pos[u]);
        while(!pq.empty()) {
            int nm = pq.top().fi;
            int x = pq.top().se.fi, y = pq.top().se.se;
            pq.pop();
            if(chk[x][y]) continue;
            chk[x][y] = true;
            chked.eb(x, y);
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(nm - r[arr[nx][ny]] < 0) continue;
                if(r[arr[nx][ny]] == -1) continue;
                if(p[nx][ny] + t[u] == 1) continue;
                if(chk[nx][ny]) continue;
                if(nx == a && ny == b) {
                    ans = true; break;
                }
                bool flag = false;
                for(int j = 0; j < 4; j++) {
                    int nnx = nx + dx[j], nny = ny + dy[j];
                    if(nnx < 0 || nnx >= h || nny < 0 || nny >= w) continue;
                    if(p[nnx][nny] + t[u] == 1) flag = true;
                }
                if(flag) continue;
                pq.em(nm - r[arr[nx][ny]], make_pair(nx, ny));
            }
            if(ans) break;
        }
        if(ans) pos[u] = make_pair(a, b);
        p[pos[u].fi][pos[u].se] = t[u];
        for(auto i : chked) chk[i.fi][i.se] = false;
        chked.clear();
    }

    for(int i = 1; i <= M; i++) {
        cout << pos[i].fi << ' ' << pos[i].se << '\n';
    }
}