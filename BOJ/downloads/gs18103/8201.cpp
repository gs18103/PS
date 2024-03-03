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

const int MAX = 3030303;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

int arr[MAX];
vector <int> num;
list <pii> dq[2];

void add(int x, int val) {
    while(!dq[0].empty() && dq[0].back().fi <= val) dq[0].pop_back();
    while(!dq[1].empty() && dq[1].back().fi >= val) dq[1].pop_back();
    dq[0].eb(val, x);
    dq[1].eb(val, x);
}

void erase(int x) {
    if(!dq[0].empty() && dq[0].front().se == x) dq[0].pop_front();
    if(!dq[1].empty() && dq[1].front().se == x) dq[1].pop_front();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t, n;
    cin >> t >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int l = 1, r = 1, ans = 1;
    add(1, arr[1]);
    while(r <= n) {
        if(l > r) {
            erase(l);
            l++;
            continue;
        }
        if(dq[0].front().fi - dq[1].front().fi > t) {
            erase(l);
            l++;
        }
        else {
            ans = max(ans, r - l + 1), r++;
            add(r, arr[r]);
        }
    }
    cout << ans;
}