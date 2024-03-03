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
const ll LINF = 9e18;

ll mymul(ll a, ll b, ll mod) {
    return (__int128_t)a * b % mod;
}

ll mypow(ll a, ll b, ll mod) {
    ll ret = 1; a = a % mod;
    while(b > 0) {
        if(b & 1) ret = mymul(a, ret, mod);
        b >>= 1;
        a = mymul(a, a, mod);
    }
    return ret;
}

bool miller_rabin(ll n, ll a) {
    if (n % a == 0) return 0;
    ll d = n - 1;
    while (1) {
        ll tmp = mypow(a, d, n);
        if (d & 1) return (tmp != 1 && tmp != n - 1);
        else if (tmp == n - 1) return 0;
        d >>= 1;
    }
}
bool is_prime(ll x) {
    for (auto& i : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
        if (x == i) return 1;
        if (x > 40 && miller_rabin(x, i)) return 0;
    }
    if (x <= 40) return 0;
    return 1;
}

ll gcd(ll x, ll y) {
    if(!y) return x;
    return gcd(y, x % y);
}

vector <ll> ans;

void factorize(ll n) {
    if(n == 1) return;
    if(n % 2 == 0) {
        ans.eb(2);
        factorize(n / 2);
        return;
    }
    if(is_prime(n)) {
        ans.eb(n);
        return;
    }

    ll a, b, c, g = n;
    auto f = [&](ll x) {
        return (c + mymul(x, x, n)) % n;
    };
    do {
        if(g == n) {
            a = b = rand() % (n - 2) + 2;
            c = rand() % 20 + 1;
        }
        a = f(a);
        b = f(f(b));
        g = gcd(abs(a - b), n);
    } while(g == 1);
    factorize(n / g), factorize(g);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n;
    cin >> n;
    factorize(n);
    sort(all(ans));

    for(auto i : ans) cout << i << '\n';
}