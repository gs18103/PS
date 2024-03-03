#include  <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;
    vector <ll> A(n), D(m+1);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> D[i];
    }

    sort(all(A));
    sort(all(D));
    reverse(all(A));
    reverse(all(D));

    int lb = 1, ub = m;
    while(lb < ub) {
        int m = lb + ub + 1 >> 1;
        ll cnt = k;
        int d = 0, idx = 0;
        bool flag = true;
        for(int i = m - 1; i >= 0; i--) {
            while(D[i] > d && idx < n) {
                ll add = 0;
                for(int j = idx; j < min(idx + cnt, (ll)n); j++) {
                    add += A[j] - 1;
                }
                idx = min(idx + cnt, (ll)n);
                cnt += add;
                d++;
            }
            if(D[i] < d) flag = false;
            else cnt--;
            if(cnt < 0) flag = false;
        }
        if(flag) lb = m;
        else ub = m - 1;
    }
    cout << lb << endl;
}