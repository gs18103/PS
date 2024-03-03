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
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector <string> s(n);
    vector <int> idx(n);
    vector <list <int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        v[i].eb(i);
        idx[i] = i;
    }
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        x = idx[x-1], y = idx[y-1];
        if(v[x].size() >= v[y].size()) {
            while(!v[y].empty()) {
                idx[v[y].front()] = x;
                v[x].push_back(v[y].front());
                v[y].pop_front();
            }
        }
        else {
            while(!v[x].empty()) {
                idx[v[x].back()] = y;
                v[y].push_front(v[x].back());
                v[x].pop_back();
            }
        }
    }
    for(int i : v[idx[0]]) {
        cout << s[i];
    }
    cout << endl;
}