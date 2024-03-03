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

ll h[MAX], ans[MAX];
vector <int> a;

void dnc(int s, int e, int l, int r) {
    if(s > e) return;
    int m = s + e >> 1;
    int idx = a[m];
    for(int i = l; i <= min(a[m], r); i++) {
        if(ans[a[m]] < (h[a[m]] + h[i]) * (a[m] - i)) {
            ans[a[m]] = (h[a[m]] + h[i]) * (a[m] - i);
            idx = i;
        }
    }

    dnc(s, m-1, l, idx);
    dnc(m+1, e, idx, r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        while(!a.empty()) {
            if(h[a.back()] > h[i]) break;
            a.pop_back();
        }
        a.eb(i);
    }
    dnc(0, a.size()-1, 1, n);
    ll ANS = 0;
    for(int i = 1; i <= n; i++) {
        ANS = max(ANS, ans[i]);
    }
    cout << ANS;
}