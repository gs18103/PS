#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define em emplace

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 20202;
const int INF = 1e9;
const ll LINF = 1e18;

int cnt[MAX];
void mysort(vector <int> &v) {
    int mx = 0;
    for(int i : v) {
        mx = max(mx, i);
        cnt[i]++;
    }
    int idx = 0;
    for(int i = mx; i >= 0; i--) {
        for(int j = 0; j < cnt[i]; j++) {
            v[idx++] = i;
        }
        cnt[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, ans = 0;
    cin >> n >> m;
    vector <int> s(m), v;
    for(int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++) {
            if(temp[j] == '1') s[j] = s[j] + 1;
            else s[j] = 0;
        }
        v = s;
        mysort(v);
        for(int j = 0; j < m; j++) {
            ans = max(ans, (j + 1) * v[j]);
        }
    }
    cout << ans;
}