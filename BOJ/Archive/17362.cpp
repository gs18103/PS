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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    int c = n % 8;
    if(c == 1) cout << 1 << endl;
    if(c == 2 || c == 0) cout << 2 << endl;
    if(c == 3 || c == 7) cout << 3 << endl;
    if(c == 4 || c == 6) cout << 4 << endl;
    if(c == 5) cout << 5 << endl;
}