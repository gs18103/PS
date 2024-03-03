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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

class UnionFindTree {
    vector <int> p;
    int sz;
public:
    void Init(int n) {
        sz = n;
        p.resize(n+1);
        for(int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }
    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(x > y) swap(x, y);
        p[y] = x;
    }
};

struct Edge {
    int a, b, c;
    Edge() {}
    Edge(int a, int b, int c) : a(a), b(b), c(c) {}
    bool operator < (const Edge &V) const {
        return c > V.c;
    }
};

struct Query {
    int a, b, w, idx;
    Query(int a, int b, int w, int idx) : a(a), b(b), w(w), idx(idx) {}
    bool operator < (const Query &V) const {
        return w > V.w;
    }
};

void solve(int n, vector <Query> &Q, multiset <Edge> &st) {
    UnionFindTree UFT;
    UFT.Init(n);
    sort(all(Q));
    vector <int> ans(Q.size());
    auto it = st.begin();
    for(auto i : Q) {
        while(it != st.end() && it->c >= i.w) {
            UFT.uni(it->a, it->b);
            it = next(it);
        }
        if(UFT.find(i.a) == UFT.find(i.b)) ans[i.idx] = 1;
        else ans[i.idx] = 0;
    }

    for(auto i : ans) {
        cout << i << '\n';
    }

    Q.clear();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while(n != 0 && m != 0) {
        vector <Edge> E(m+1);
        multiset <Edge> st;
        for(int i = 1; i <= m; i++) {
            cin >> E[i].a >> E[i].b >> E[i].c;
            st.em(E[i]);
        }
        int q;
        cin >> q;
        vector <Query> Q;
        while(q--) {
            string s;
            cin >> s;
            if(s == "S") {
                int a, b, w;
                cin >> a >> b >> w;
                Q.eb(a, b, w, Q.size());
            }   
            else {
                solve(n, Q, st);
                int r, c;
                cin >> r >> c;
                st.erase(st.find(E[r]));
                E[r].c = c;
                st.em(E[r]);
            }
        }   
        solve(n, Q, st);
        cin >> n >> m;
    }
}