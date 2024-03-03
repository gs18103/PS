#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

int S[MAX], P[MAX], pa[MAX], idx[MAX], ans[MAX], in[MAX];
ll m, C[MAX], d[MAX];

struct BigAndSmall {
    map <int, priority_queue <ll> > mp;
    multiset <pair <ll, int>, greater <pair <ll, int> > > st;
    multiset <pair <ll, int> > st2;
    ll sum = 0, shift = 0;
    int cnt = 0, sz = 0;
    void merge(BigAndSmall &X) {
        sz += X.sz;
        for(auto i : X.st2) {
            st2.em(i.fi + X.shift - shift, i.se);
        }
        for(auto &i : X.mp) {
            while(!i.se.empty()) {
                ll x = i.se.top() + X.shift;
                i.se.pop();
                priority_queue <ll> &tmp = mp[i.fi];
                tmp.em(x - shift);
                st.em(x - shift, i.fi);
                cnt++;
                sum += x;
                if(tmp.size() > P[i.fi]) {
                    sum -= tmp.top() + shift;
                    cnt--;
                    st.erase(st.find({tmp.top(), i.fi}));
                    tmp.pop();
                    while(!st2.empty() && mp[st2.begin()->se].size() == P[st2.begin()->se]) st2.erase(st2.begin());
                    while(!st2.empty() && sum + st2.begin()->fi + shift <= m) {
                        sum += st2.begin()->fi + shift;
                        cnt++;
                        mp[st2.begin()->se].em(st2.begin()->fi);
                        st.em(st2.begin()->fi, st2.begin()->se);
                        st2.erase(st2.begin());
                    }
                }   
                if(sum > m) {
                    sum -= st.begin()->fi + shift;
                    cnt--;
                    st2.em(st.begin()->fi, st.begin()->se);
                    mp[st.begin()->se].pop();
                    st.erase(st.begin());
                }
            }
        }
    }
    void add(ll s) {
        shift += s;
        sum += s * cnt;
        while(sum > m) {
            sum -= st.begin()->fi + shift;
            cnt--;
            st2.em(st.begin()->fi, st.begin()->se);
            mp[st.begin()->se].pop();
            st.erase(st.begin());
        }
    }
    void Init(int x) {
        if(C[x] > m) return;
        mp[x].em(C[x]);
        st.em(C[x], x);
        sum = C[x];
        cnt = 1;
        sz = 1;
    }
} dp[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k >> m;
    for(int i = 2; i <= n; i++) {
        cin >> pa[i] >> d[i];
        in[pa[i]]++;
    }
    for(int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    for(int i = 1; i <= k; i++) {
        cin >> C[i];
    }
    for(int i = 1; i <= k; i++) {
        cin >> P[i];
    }

    queue <int> q;
    for(int i = 1; i <= n; i++) {
        idx[i] = i;
        dp[i].Init(S[i]);
        if(in[i] == 0) q.em(i);
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        ans[x] = dp[idx[x]].cnt;
        dp[idx[x]].add(d[x]);
        if(dp[idx[x]].sz > dp[idx[pa[x]]].sz) swap(idx[x], idx[pa[x]]);
        dp[idx[pa[x]]].merge(dp[idx[x]]);
        in[pa[x]]--;
        if(in[pa[x]] == 0) q.em(pa[x]);
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}