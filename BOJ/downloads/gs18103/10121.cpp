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

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;

int R[MAX];
vector <int> L[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; string s;
    cin >> n >> s;
    priority_queue <pii> pq;
    int p = -1, num = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'p') {
            num++;
            p = i;
            pq.em(num, i);
        }
        else num--, R[i] = -1;
        while(!pq.empty() && pq.top().fi > num + 1) {
            R[pq.top().se] = p;
            pq.pop();
        }
    }
    while(!pq.empty()) {
        R[pq.top().se] = p;
        pq.pop();
    }
    p = n, num = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'p') {
            num++;
            p = i;
            pq.em(num, i);
        }
        else num--;
        while(!pq.empty() && pq.top().fi > num + 1) {
            L[p].eb(pq.top().se);
            pq.pop();
        }
    }
    while(!pq.empty()) {
        L[p].eb(pq.top().se);
        pq.pop();
    }
    int idx = -1, mx = -1, ans = 0;
    set <int> st;
    for(int i = 0; i < n; i++) {
        if(R[i] == -1) continue;
        for(auto j : L[i]) st.em(j);
        auto it = st.upper_bound(R[i]);
        if(it != st.begin()) ans = max(ans, *prev(it) - i + 1);
    }
    cout << ans;
}