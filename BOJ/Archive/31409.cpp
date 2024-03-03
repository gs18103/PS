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

int a[MAX];
bool chk[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    vector <int> v;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == i) cnt++, v.eb(i);
    }

    cout << cnt << '\n';
    if(cnt == 1) {
        for(int i = 1; i <= n; i++) {
            if(a[i] == i) cout << i % n + 1 << ' ';
            else cout << a[i] << ' ';
        }
    }
    else {
        int idx = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] == i) cout << v[(++idx)%v.size()] << ' ';
            else cout << a[i] << ' ';
        }
    }
}