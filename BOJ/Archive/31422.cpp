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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll A = 0, O = 0, X = 0;
    for(int i = 0; i < 30; i++) {
        int idx = 0;
        for(int j = 0; j < n; j++) {
            idx = max(idx, j);
            while(idx + 1 < n && (a[idx+1] >> i & 1)) idx++;
            if(a[j] >> i & 1) A = (A + (1LL << i) * (idx - j + 1)) % mod;
        }

        idx = -1;
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            while(idx + 1 < n && cnt == 0) {
                idx++;
                cnt += (a[idx] >> i & 1);
            }
            if(cnt) O = (O + (1LL << i) * (n - idx)) % mod;
            if(a[j] >> i & 1) cnt--;
        }

        bool flag = false;
        int odd = 0, even = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] >> i & 1) flag = !flag;
            if(flag) odd++;
            else even++;
        }
        flag = false;
        for(int j = 0; j < n; j++) {
            if(!flag) X = (X + (1LL << i) * odd) % mod;
            else X = (X + (1LL << i) * even) % mod;

            if(a[j] >> i & 1) flag = !flag;
            if(flag) odd--;
            else even--;
        }
    }
    cout << A << ' ' << O << ' ' << X << endl;
}