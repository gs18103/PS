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

const int MAX = 1010101;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

int arr[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] -= i - 1;
    }
    priority_queue <int> L;
    L.em(arr[1]);
    ll s = 0;
    for(int i = 2; i <= n; i++) {
        if(arr[i] < L.top()) {
            s += L.top() - arr[i];
            L.pop();
            L.em(arr[i]);
            L.em(arr[i]);
        }
        else {
            L.em(arr[i]);
        }
    }
    cout << s << endl;
}