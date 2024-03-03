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

const int MAX = 505050;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> v;
int sum[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    int len = 1;
    string s, t;
    cin >> t;
    v.eb(0);
    for(int i = 2; i <= n; i++) {
        cin >> s;
        if(s == t) len++;
        else {v.eb(len); len = 1;}
        t = s;
    }
    v.eb(len);
    for(int i = 1; i < v.size(); i++) {
        sum[i] = sum[i-1] + v[i];
    }
    int lb = 0, ub = 1, ans = INF;
    while(ub < v.size()) {
        if(sum[ub] - sum[lb] < l) ub++;
        else if(sum[ub] - sum[lb] > l) lb++;
        else {
            if((ub - lb) & 1 || lb == 0 || ub == v.size() - 1) ans = min(ans, (ub - lb) / 2);
            lb++;
        }
    }
    cout << ans;
}