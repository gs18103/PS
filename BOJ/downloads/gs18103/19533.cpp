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
const int INF = 1e9;
const ll LINF = 1e18;

string ans_short[21] = {"", "1", "-2", "1-3", "-2-4", "1-3-5", "-2-4-6", "1-3-5-7", 
"-2-4-6-8", "1-3-5-7-9", "1-3-5-7-10", "-2-4-6-8-11", "1-3-5-7-9-12", "1-3-5-7-10-13", 
"-2-4-6-8-11-14", "1-3-5-7-9-12-15", "1-3-5-7-10-13-16", "-2-4-6-8-11-14-17", 
"1-3-5-7-9-12-15-18", "1-3-5-7-10-13-16-19", "-2-4-6-8-11-14-17-20"};
string ans_long[3] = {"1-3-5-7-9-12-15-1...", "1-3-5-7-10-13-16-...", "-2-4-6-8-11-14-17..."};

ll d1[1010101], d2[1010101], zero[1010101], modzero[1010101];

ll pow(ll a, ll b, ll mod) {
    ll r = 1;
    while(b) {
        if(b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

string solve(ll a, ll b) {
    if(b <= 1) {
        if(a * pow(10, b, 1000) <= 20) {
            return ans_short[a * pow(10, b, 1000)];
        }
    }
    
    ll digit = b;
    ll temp = a;
    while(temp > 0) {
        temp /= 10; 
        digit++;
    }
    ll mm = (a * pow(10, b, digit + 1)) % (digit + 1);
    mm = (mm + modzero[digit]) % (digit + 1);
    if(mm < d1[digit]) return ans_long[0];
    else if(mm < d2[digit]) return ans_long[1];
    else return ans_long[2];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    d1[2] = 1, d2[2] = 2, zero[2] = 1, modzero[2] = 0;
    for(int i = 3; i <= 1000100; i++) {
        ll temp = (pow(10, i - 1, i) + i - 1) % i;
        ll dv = (modzero[i-1] + temp) % i;
        d1[i] = d1[i-1], d2[i] = d2[i-1];
        if(dv < d1[i-1]) d1[i]++;
        if(dv < d2[i-1]) d2[i]++;
        zero[i] = dv + 1;
        modzero[i] = (zero[i] - pow(10, i - 1, i + 1) + i + 1) % (i + 1);
    }

    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << '\n';
    }
}