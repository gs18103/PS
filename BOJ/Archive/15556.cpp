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
typedef pair <int, ll> pil;

const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int N, M, S, T, U, V;
    cin >> N >> M >> S >> T >> U >> V;
    vector <vector <pil>> g(N+1);
    for(int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].eb(v, c), g[v].eb(u, c);
    }

    auto Djikstra = [&](vector <ll> &d, int st) {
        d[st] = 0;
        priority_queue <pll> pq;
        vector <bool> chk(N+1);
        pq.em(0, st);
        while(!pq.empty()) {
            int x = pq.top().se;
            pq.pop();
            if(chk[x]) continue;
            chk[x] = true;
            for(auto [y, c] : g[x]) {
                if(d[y] > d[x] + c) {
                    d[y] = d[x] + c;
                    pq.em(-d[y], y);
                }
            }
        }
    };

    vector <ll> d_S(N+1, LINF), d_T(N+1, LINF), d_U(N+1, LINF), d_V(N+1, LINF);
    Djikstra(d_S, S);
    Djikstra(d_T, T);
    Djikstra(d_U, U);
    Djikstra(d_V, V);

    auto get_pre = [&](vector <vector <int>> &pre, vector <ll> &d, int tar) {
        queue <int> q;
        vector <bool> chk(N+1);
        chk[tar] = true;
        q.em(tar);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(auto [y, c] : g[x]) {
                if(d[x] == d[y] + c) {
                    pre[x].eb(y);
                    if(!chk[y]) {
                        q.em(y);
                        chk[y] = true;
                    }
                }
            }
        }
    };

    vector <vector <int>> pre_S(N+1), pre_T(N+1);
    get_pre(pre_S, d_S, T);
    get_pre(pre_T, d_T, S);

    auto get_dp = [&](vector <vector <int>> &pre, vector <ll> &dp_U, vector <ll> &dp_V, int tar) {
        vector <int> ind(N+1);
        queue <int> q;
        for(int i = 1; i <= N; i++) {
            for(int j : pre[i]) {
                ind[j]++;
            }
        }
        q.em(tar);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            dp_U[x] = min(dp_U[x], d_U[x]), dp_V[x] = min(dp_V[x], d_V[x]);
            for(int i : pre[x]) {
                ind[i]--;
                dp_U[i] = min(dp_U[i], dp_U[x]);
                dp_V[i] = min(dp_V[i], dp_V[x]);
                if(ind[i] == 0) q.em(i);
            }
        }
    };

    vector <ll> dp_SU(N+1, LINF), dp_SV(N+1, LINF), dp_TU(N+1, LINF), dp_TV(N+1, LINF);
    get_dp(pre_S, dp_SU, dp_SV, T);
    get_dp(pre_T, dp_TU, dp_TV, S);

    ll ans = LINF;
    for(int i = 1; i <= N; i++) {
        ans = min({ans, dp_SU[i] + dp_TV[i], dp_SV[i] + dp_TU[i]});
    }
    cout << min(ans, d_U[V]) << '\n';
}