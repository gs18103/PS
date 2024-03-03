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

pll arr[3*MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].fi >> arr[i].se;
        arr[i].fi += arr[i].se;
    }
    sort(arr + 1, arr + n + 1);
    priority_queue <ll> pq;
    ll h = 0;
    for(int i = 1; i <= n; i++) {
        h += arr[i].se;
        pq.em(arr[i].se);
        while(h > arr[i].fi) {
            h -= pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << endl;
}