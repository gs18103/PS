#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define INF 2000000000

using namespace std;
typedef long long ll;
typedef pair <int, ll> pii;

bool chk[202020];
int c[202020], dep[202020];
vector <pii> g[202020];
vector <int> ct[202020];

int dfs(int x, int pa) {
    c[x] = 1;
    for(auto i : g[x]) {
        if(i.fi == pa) continue;
        c[x] += dfs(i.fi, x);
    }
    return c[x];
}

int find_cen(int x, int pa){
    int sz = 1, mx = 0, mxi;
    for(auto i : g[x]){
        if(chk[i.fi]) continue;
        sz += c[i.fi];
        if(c[i.fi] > mx){
            mx = c[i.fi];
            mxi = i.fi;
        }
    }
    if(mx <= sz/2) return x;
    c[x]= sz - mx;
    return find_cen(mxi, x);
}

int make_ct(int cur, int pa){
    int x = find_cen(cur, pa);
    chk[x] = true;
    for(auto i : g[x]){
        if(chk[i.fi]) continue;
        ct[x].eb(make_ct(i.fi, x));
    }
    return x;
}

int ans = INF;
ll k;
void get_ans(int x) {
    chk[x] = true;
    map <int, int> mp;
    mp.insert({0, 0});
    for(auto i : g[x]) {
        if(chk[i.fi]) continue;
        map <int, int> tmp;
        queue <pair <pii, int> > q;
        q.push({i, x});
        int cnt = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int v = q.front().fi.fi, dis = q.front().fi.se, pa = q.front().se;
                q.pop();
                if(dis > k) continue;
                if(tmp.find(dis) == tmp.end()) tmp.insert({dis, cnt});
                if(mp.find(k-dis) != mp.end()) ans = min(ans, mp[k-dis] + cnt);
                for(auto i : g[v]) {
                    if(i.fi == pa || chk[i.fi]) continue;
                    q.push({{i.fi, dis+i.se}, v});
                }
            }
            cnt++;
        }
        for(auto it = tmp.begin(); it != tmp.end(); it++) {
            if(mp.find(it->fi) == mp.end()) mp.insert(*it);
            else mp[it->fi] = min(mp[it->fi], it->se);
        }
    }
    for(auto i : ct[x]) {
        if(chk[i]) continue;
        get_ans(i);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w; u++, v++;
        g[u].eb(v, w), g[v].eb(u, w);
    }
    dfs(1, 0);
    int ctr = make_ct(1, 0);

    for(int i = 1; i <= n; i++) {
        chk[i] = false;
    }
    get_ans(ctr);
    if(ans == INF) cout << -1;
    else cout << ans;
}