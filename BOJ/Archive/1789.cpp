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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll s;
    cin >> s;
    ll i = 1;
    while(i * (i + 1) / 2 <= s) i++;
    cout << i - 1;
}