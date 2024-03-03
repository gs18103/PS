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

int a[MAX], n;

void no() { cout << "1 1\n1 1"; }

void rvs(int l, int r) {
    vector <int> tmp;
    for(int i = l; i <= r; i++) {
        tmp.eb(a[i]);
    }
    reverse(all(tmp));
    for(int i = l; i <= r; i++) {
        a[i] = tmp[i-l];
    }
}

pii can() {
    int L = n, R = 1;
    for(int i = 1; i <= n; i++) {
        if(a[i] != i) {L = i; break;}
    }
    for(int i = n; i >= 1; i--) {
        if(a[i] != i) {R = i; break;}
    }
    if(L > R) return pii(1, 1);
    rvs(L, R);
    bool flag = false;
    for(int i = 1; i <= n; i++) {
        if(a[i] != i) flag = true;
    }
    rvs(L, R);
    if(flag) return pii(0, 0);
    return pii(L, R);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int L = n, R = 1;
    for(int i = 1; i <= n; i++) {
        if(a[i] != i) {L = i; break;}
    }
    for(int i = n; i >= 1; i--) {
        if(a[i] != i) {R = i; break;}
    }
    if(L > R) { no(); return 0;}
    
    int Lpos, Rpos;
    for(int i = 1; i <= n; i++) {
        if(a[i] == L) Lpos = i;
        if(a[i] == R) Rpos = i;
    }
    
    rvs(L, Lpos);
    pii tmp = can();
    if(tmp.fi != 0) {
        cout << L << ' ' << Lpos << '\n' << tmp.fi << ' ' << tmp.se;
        return 0;
    }
    rvs(L, Lpos);
    
    rvs(Rpos, R);
    tmp = can();
    cout << Rpos << ' ' << R << '\n' << tmp.fi << ' ' << tmp.se;
}