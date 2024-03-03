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

vector <int> party[MAX];
int inf_fin[MAX], inf_ini[MAX], inf_test[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int u;
            cin >> u;
            party[i].eb(u);
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> inf_fin[i];
        inf_ini[i] = inf_fin[i];
    }

    for(int i = m; i  >= 1; i--) {
        bool flag = false;
        for(auto j : party[i]) {
            if(inf_ini[j] == 0) {
                flag = true;
                break;
            }
        }
        if(flag) {
            for(auto j : party[i]) {
                inf_ini[j] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        inf_test[i] = inf_ini[i];
    }

    for(int i = 1; i <= m; i++) {
        bool flag = false;
        for(auto j : party[i]) {
            if(inf_test[j] == 1) {
                flag = true;
                break;
            }
        }
        if(flag) {
            for(auto j : party[i]) {
                inf_test[j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(inf_test[i] != inf_fin[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        cout << inf_ini[i] << ' ';
    }
}