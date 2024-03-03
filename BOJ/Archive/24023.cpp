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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector <int> a(n+1), cnt(30);
    int l = 1, val = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        val |= a[i];
        for(int j = 0; j < 30; j++) {
            if(a[i] >> j & 1) cnt[j]++;
        }
        while(val > k) {
            for(int j = 0; j < 30; j++) {
                if(a[l] >> j & 1) {
                    cnt[j]--;
                    if(cnt[j] == 0) val -= (1 << j);
                }
            }
            l++;
        }
        if(val == k) {
            cout << l << ' ' << i;
            return 0;
        }
    }
    cout << -1;
}