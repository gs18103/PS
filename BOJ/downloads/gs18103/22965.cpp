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

const int MAX = 1010101;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll mod = 998244353;

int a[202020];
vector <int> num;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    int cnt = 0, ans = 1;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        num.eb(a[i]);
        if(i && a[i] < a[i-1]) flag = false;
    }
    if(flag) {
        cout << 1 << endl;
        return 0;
    }
    sort(all(num));
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(all(num), a[i]) - num.begin();
    }

    for(int i = 0; i < n; i++) {
        if(a[i] != (a[0] + i) % n) flag = true;
    }
    if(!flag) cout << 2 << endl;
    else cout << 3 << endl;
}