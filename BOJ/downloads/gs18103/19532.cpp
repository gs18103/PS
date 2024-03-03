#include <bits/stdc++.h>
#define emplace_back eb
#define emplace em
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    for(int x = -999; x <= 999; x++) {
        for(int y = -999; y <= 999; y++) {
            if(a * x + b * y == c && d * x + e * y == f) {
                cout << x << ' ' << y << endl;
                return 0;
            }
        }
    }
}