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

const int MAX = 303030;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll mod = 998244353;

struct SEG {
    struct Node {
        int m1 = 0, m2 = 0;
    };
    vector <Node> tree;
    SEG(int n) {
        tree.resize(4*n+10);
    }

    Node mer(Node a, Node b) {
        Node ret;
        if(a.m1 < b.m1) swap(a, b);
        ret.m1 = a.m1;
        ret.m2 = max(a.m2, b.m1);
        return ret;
    }

    void update(int node, int s, int e, int k, int val) {
        if(s == e) {
            tree[node].m1 += val;
            return;
        }
        int m = (s + e) / 2;
        if(k <= m) update(node*2, s, m, k, val);
        else update(node*2+1, m+1, e, k, val);
        tree[node] = mer(tree[node*2], tree[node*2+1]);
    }

    Node cal(int node, int s, int e, int l, int r) {
        if(s > r || e < l) return {0, 0};
        if(s >= l && e <= r) return tree[node];
        int m = (s + e) / 2;
        return mer(cal(node*2, s, m, l, r), cal(node*2+1, m+1, e, l, r));
    }
};

vector <int> X, Y, XL[MAX], YL[MAX], sumx, sumy;
int x[MAX], y[MAX], v[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> v[i];
        X.eb(x[i]), Y.eb(y[i]);
    }
    sort(all(X));
    X.erase(unique(all(X)), X.end());
    sort(all(Y));
    Y.erase(unique(all(Y)), Y.end());

    SEG stx(X.size()), sty(Y.size());
    
    for(int i = 1; i <= n; i++) {
        int xc = lower_bound(all(X), x[i]) - X.begin() + 1;
        int yc = lower_bound(all(Y), y[i]) - Y.begin() + 1;
        XL[xc].eb(i);
        YL[yc].eb(i);
        stx.update(1, 1, X.size(), xc, v[i]);
        sty.update(1, 1, Y.size(), yc, v[i]);
    }

    int ans = 0;

    for(int i = 1; i <= X.size(); i++) {
        int sum = 0;
        for(auto j : XL[i]) {
            sum += v[j];
            int yc = lower_bound(all(Y), y[j]) - Y.begin() + 1;
            sty.update(1, 1, Y.size(), yc, -v[j]);
        }
        sumx.eb(sum);

        ans = max(ans, sty.tree[1].m1 + sty.tree[1].m2 + sum);

        for(auto j : XL[i]) {
            int yc = lower_bound(all(Y), y[j]) - Y.begin() + 1;
            sty.update(1, 1, Y.size(), yc, v[j]);
        }
    }
    for(int i = 1; i <= Y.size(); i++) {
        int sum = 0;
        for(auto j : YL[i]) {
            sum += v[j];
            int xc = lower_bound(all(X), x[j]) - X.begin() + 1;
            stx.update(1, 1, X.size(), xc, -v[j]);
        }
        sumy.eb(sum);

        ans = max(ans, stx.tree[1].m1 + stx.tree[1].m2 + sum);

        for(auto j : YL[i]) {
            int xc = lower_bound(all(X), x[j]) - X.begin() + 1;
            stx.update(1, 1, X.size(), xc, v[j]);
        }
    }
    sort(all(sumx)), sort(all(sumy));
    int szx = sumx.size(), szy = sumy.size();
    int ssx = 0, ssy = 0;
    for(int i = 1; i <= min(3, szx); i++) {
        ssx += sumx[szx-i];
    }
    for(int i = 1; i <= min(3, szy); i++) {
        ssy += sumy[szy-i];
    }
    ans = max(ans, ssx);
    ans = max(ans, ssy);
    cout << ans << endl;
}