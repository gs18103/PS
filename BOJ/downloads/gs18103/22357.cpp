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

bool chk[2505];

int main() {
    ios::sync_with_stdio(false);

    for(int i = 2; i <= 2500; i++) {
        if(chk[i]) continue;
        for(int j = i * i; j <= 2500; j += i) {
            chk[j] = true;
        }
    }
    
    int k, n;
    cin >> k >> n;
    vector <int> pp;
    for(int i = 2000; pp.size() < k; i++) {
        if(!chk[i]) pp.eb(i);
    }
    for(int i = 0; i < k; i++) {
        for(int j = 1; j <= n; j++) {
            cout << pp[i] * j << ' ';
        }
        cout << '\n';
    }
}