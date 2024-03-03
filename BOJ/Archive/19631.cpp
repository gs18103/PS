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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n = 100;
    cout << n << '\n';
    for(int i = 1; i < n; i++) {
        cout << "1 ";
    }
    cout << '\n';
    for(int i = 2; i < n - 1; i++) {
        if(i & 1) cout << "100 100 ";
        else cout << "1 100 ";
        for(int j = 1; j <= n - i - 2; j++) {
            cout << "1 ";
        }
        cout << '\n';   
    }
    cout << "100 ";
}