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

string t[MAX];
vector <vector <int> > s, sum[5];
int p[404];

bool waldo(int sx, int sy, int ex, int ey) {
    for(int i = 0; i < 5; i++) {
        if(sum[i][ex][ey] - sum[i][sx-1][ey] - sum[i][ex][sy-1] + sum[i][sx-1][sy-1] == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        cin >> t[i];
    }

    if(h > w) {
        swap(h, w);
        s.resize(h+1);
        for(int i = 0; i <= h; i++) s[i].resize(w+1);
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                s[i][j] = t[j-1][i-1] - 'A';
            }
        }
    }
    else {
        s.resize(h+1);
        for(int i = 0; i <= h; i++) s[i].resize(w+1);
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                s[i][j] = t[i-1][j-1] - 'A';
            }
        }
    }
    for(int i = 0; i < 5; i++) {
        sum[i].resize(h+1);
        for(int j = 0; j <= h; j++) {
            sum[i][j].resize(w+1);
        }
    }

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            sum[0][i][j] = sum[0][i-1][j] + sum[0][i][j-1] - sum[0][i-1][j-1] + (s[i][j] == (int)('W' - 'A'));
            sum[1][i][j] = sum[1][i-1][j] + sum[1][i][j-1] - sum[1][i-1][j-1] + (s[i][j] == (int)('A' - 'A'));
            sum[2][i][j] = sum[2][i-1][j] + sum[2][i][j-1] - sum[2][i-1][j-1] + (s[i][j] == (int)('L' - 'A'));
            sum[3][i][j] = sum[3][i-1][j] + sum[3][i][j-1] - sum[3][i-1][j-1] + (s[i][j] == (int)('D' - 'A'));
            sum[4][i][j] = sum[4][i-1][j] + sum[4][i][j-1] - sum[4][i-1][j-1] + (s[i][j] == (int)('O' - 'A'));
        }
    }
    int ans = INF;
    for(int i = 1; i <= h; i++) {
        for(int j = i; j <= h; j++) p[j] = 1;
        for(int j = 1; j <= w; j++) {
            for(int k = i; k <= h; k++) {
                while(p[k] < j) p[k]++;
                while(!waldo(i, j, k, p[k]) && p[k] <= w) p[k]++;
                if(p[k] <= w) ans = min(ans, (k - i + 1) * (p[k] - j + 1));
            }
        }
    }
    if(ans == INF) cout << "impossible";
    else cout << ans;
}