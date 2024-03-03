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

char arr[101][101];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    map <char, char> mp;
    mp['.'] = '.';
    mp['O'] = 'O';
    mp['-'] = '|';
    mp['|'] = '-';
    mp['/'] = '\\';
    mp['\\'] = '/';
    mp['^'] = '<';
    mp['<'] = 'v';
    mp['v'] = '>';
    mp['>'] = '^';

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = m; i >= 1; i--) {
        for(int j = 1; j <= n; j++) {
            cout << mp[arr[j][i]];
        }
        cout << '\n';
    }
}