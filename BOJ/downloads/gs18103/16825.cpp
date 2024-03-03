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
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll mod = 1e9+7;

int p[MAX], rnk[MAX], sz[MAX], cur[MAX];
pii arr[MAX];
vector <pii> E[4*MAX];
vector <int> bp[4*MAX], br[4*MAX], prime, ans, bdsz[4*MAX];
vector <pii> bsz[4*MAX];
multiset <int, greater <int> > cnt[70];
map <int, int> rem;
ll powed[70][MAX], inv[MAX];
int pp[70][MAX];

ll L = 1;

ll mypow(ll a, ll b) {
    ll ret = 1;
    while(b > 0) {
        if(b & 1) ret = (ret * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return ret;
}

void mul(ll x) {
    L = (L * x) % mod;
}

void div(ll x) {
    L = (L * inv[x]) % mod;
}

void add(ll x) {
    for(int i = 0; i < prime.size(); i++) {
        int tcnt = pp[i][x];
        if(tcnt == 0) continue;
        x /= powed[i][tcnt];
        int tt = *cnt[i].begin();
        cnt[i].em(tcnt);
        if(tcnt > tt) {
            mul(powed[i][tcnt - tt]);
        }
    }
    if(x != 1) {
        rem[x]++;
        if(rem[x] == 1) mul(x);
    }
}

void del(ll x) {
    for(int i = 0; i < prime.size(); i++) {
        int tcnt = pp[i][x];
        if(tcnt == 0) continue;
        x /= powed[i][tcnt];
        cnt[i].erase(cnt[i].find(tcnt));
        int tt = *cnt[i].begin();
        if(tcnt > tt) div(powed[i][tcnt - tt]);
    }
    if(x != 1) {
        rem[x]--;
        if(rem[x] == 0) div(x);
    }
}

void update(int node, int s, int e, int l, int r, pii k) {
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        E[node].eb(k);
        return;
    }
    int m = (s + e) / 2;
    update(node*2, s, m, l, r, k);
    update(node*2+1, m+1, e, l, r, k);
}

int find(int x) {
    if(x == p[x]) return x;
    return find(p[x]);
}

void uni(int x, int y, int node) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(rnk[x] < rnk[y]) swap(x, y);
    bsz[node].eb(x, sz[x]);
    bsz[node].eb(y, sz[y]);
    bp[node].eb(y);
    del(sz[x]);
    del(sz[y]);
    sz[x] += sz[y];
    add(sz[x]);
    bsz[node].eb(x, -1);
    p[y] = x;
    if(rnk[x] == rnk[y]) {
        br[node].eb(x);
        rnk[x]++;
    }
}

void dnc(int node, int s, int e) {
    for(auto i : E[node]) {
        uni(i.fi, i.se, node);
    }
    if(s == e) {
        ans.eb(L);
    }
    else {
        int m = (s + e) / 2;
        dnc(node*2, s, m);
        dnc(node*2+1, m+1, e);
    }
    for(auto i : br[node]) rnk[i]--;
    for(auto i : bp[node]) p[i] = i;
    reverse(all(bsz[node]));
    for(auto i : bsz[node]) {
        if(i.se == -1) del(sz[i.fi]); 
        else {
            sz[i.fi] = i.se;
            add(sz[i.fi]);
        }
    }
}

bool chk[400];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 2; i * i <= n; i++) {
        if(chk[i]) continue;
        prime.eb(i);
        for(ll j = i * i; j * j <= n; j += i) {
            chk[j] = true;
        }
    }

    for(int i = 0; i < prime.size(); i++) {
        powed[i][0] = 1;
        for(int j = 1; j <= n; j++) {
            powed[i][j] = (powed[i][j-1] * prime[i]) % mod;
        }
        for(int j = prime[i]; j <= n; j += prime[i]) {
            int temp = j;
            while(temp % prime[i] == 0) {
                temp /= prime[i];
                pp[i][j]++;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        inv[i] = mypow(i, mod - 2);
    }

    for(int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
        cur[i] = i;
    }
    map <pii, int> mp;
    for(int i = 1; i <= n; i++) {
        mp[{i, i}] = 1;
    }
    for(int i = 1; i <= q; i++) {
        cin >> arr[i].fi >> arr[i].se;
        update(1, 1, q, mp[{arr[i].fi, cur[arr[i].fi]}], i - 1, {arr[i].fi, cur[arr[i].fi]});
        update(1, 1, q, mp[{arr[i].se, cur[arr[i].se]}], i - 1, {arr[i].se, cur[arr[i].se]}); 
        mp.erase({arr[i].fi, cur[arr[i].fi]});
        mp.erase({arr[i].se, cur[arr[i].se]});
        int temp = cur[arr[i].fi];
        cur[arr[i].fi] = cur[arr[i].se];
        cur[arr[i].se] = temp;
        mp[{arr[i].fi, cur[arr[i].fi]}] = i;
        mp[{arr[i].se, cur[arr[i].se]}] = i;
    }

    for(auto i : mp) {
        update(1, 1, q, i.se, q, i.fi);
    }
    
    dnc(1, 1, q);

    for(int i : ans) {
        cout << i << '\n';
    }
}