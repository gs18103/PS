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

const int MAX = 101010;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

int arr[3*MAX], dp[3*MAX];
vector <int> carr;

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mx = arr[0];
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(i > 0 && s[i] != s[i-1]) {
            if(flag) carr.eb(mx);
            flag = true;
            mx = arr[i];
        }
        else mx = max(mx, arr[i]);
    }
    sort(all(carr));
    ll ans = 0;
    int sz = carr.size();
    while(carr.size() > sz/2) {
        ans += carr.back();
        carr.pop_back();
    }
    cout << ans << endl;
}