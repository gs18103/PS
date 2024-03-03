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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int F[MAX], S[MAX];
ll sum[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; ll m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> F[i] >> S[i];
        sum[i] = sum[i-1] + F[i];
    }
    int idx = 1, ans = INF;
    multiset <int> st;
    st.em(S[1]);
    for(int i = 1; i <= n; i++) {
        while(idx <= n && sum[idx] - sum[i-1] < m) {
            idx++; 
            st.em(S[idx]);
        }
        if(idx > n) break;
        ans = min(ans, *st.rbegin());
        st.erase(st.find(S[i]));
    }
    cout << ans;
}