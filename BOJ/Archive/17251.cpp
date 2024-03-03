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

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;

int L[MAX], R[MAX], A[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for(int i = 1; i <= n; i++) {
        L[i] = max(L[i-1], A[i]);
    }
    for(int i = n; i >= 1; i--) {
        R[i] = max(R[i+1], A[i]);
    }
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(L[i] > R[i+1]) cnt++;
        if(L[i] < R[i+1]) cnt--;
    }
    if(cnt > 0) cout << "R";
    if(cnt == 0) cout << "X";
    if(cnt < 0) cout << "B";
}