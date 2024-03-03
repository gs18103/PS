#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

int cnt[26];
ll fact[30];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        cnt[s[i]-'A']++;
    }
    fact[0] = 1;
    for(int i = 1; i <= s.size(); i++) {
        fact[i] = fact[i-1] * i;
    }

    ll ans = 1;
    for(int i = 0; i < s.size(); i++) {
        int tmp = (int)(s[i] - 'A');
        for(int j = 0; j < tmp; j++) {
            if(cnt[j] > 0) {
                ll val = fact[s.size()-i-1];
                cnt[j]--;
                for(int k = 0; k < 26; k++) {
                    val /= fact[cnt[k]];
                }
                cnt[j]++;
                ans += val;
            }
        }
        cnt[tmp]--;
    }
    cout << ans;
}