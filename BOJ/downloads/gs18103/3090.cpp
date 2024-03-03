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

ll A[MAX], B[MAX];
bool chk[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; ll k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll lb = 0, ub = 1e9;
    while(lb < ub) {
        ll m = lb + ub >> 1;
        ll sum = 0;
        priority_queue <pll, vector <pll>, greater <pll> > pq;
        for(int i = 1; i <= n; i++) {
            pq.em(A[i], i);
            B[i] = A[i];
        }
        while(!pq.empty()) {
            int x = pq.top().se;
            pq.pop();
            if(chk[x]) continue;
            if(x > 1 && B[x-1] > B[x] + m) {
                sum += B[x-1] - B[x] - m;
                B[x-1] = B[x] + m;
                pq.em(B[x-1], x-1);
            }
            if(x < n && B[x+1] > B[x] + m) {
                sum += B[x+1] - B[x] - m;
                B[x+1] = B[x] + m;
                pq.em(B[x+1], x+1);
            }
        }
        if(sum <= k) ub = m;
        else lb = m + 1;
    }
    priority_queue <pll, vector <pll>, greater <pll> > pq;
    for(int i = 1; i <= n; i++) {
        pq.em(A[i], i);
        B[i] = A[i];
    }
    while(!pq.empty()) {
        int x = pq.top().se;
        pq.pop();
        if(chk[x]) continue;
        if(x > 1 && B[x-1] > B[x] + lb) {
            B[x-1] = B[x] + lb;
            pq.em(B[x-1], x-1);
        }
        if(x < n && B[x+1] > B[x] + lb) {
            B[x+1] = B[x] + lb;
            pq.em(B[x+1], x+1);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << B[i] << ' ';
    }
}