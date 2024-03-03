#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define em emplace

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int INF = 1e9;
const ll LINF = 1e18;

string a[1030];
int log_2[1030];

void print_ans(vector <int> ans, int n) {
    vector <int> tmp;
    while(n > 1) {
        for(int i = 0; i < n; i += 2) {
            cout << ans[i] << ' ' << ans[i+1] << '\n';
            if(a[ans[i]][ans[i+1]] == '1') tmp.eb(ans[i]);
            else tmp.eb(ans[i+1]);
        }
        n >>= 1;
        ans = tmp;
        tmp.clear();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i = 2; i <= 1024; i++) {
        log_2[i] = log_2[i/2] + 1;
    }
    int n;
    while(cin >> n) {
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = " " + a[i];
        }
        vector <vector <int> > v(n+1);
        vector <int> num;
        for(int i = 2; i <= n; i++) {
            if(a[1][i] == '1') {
                num.eb(i);
                continue;
            }
            for(int j = 1; j <= n; j++) {
                if(a[1][j]  == '1' && a[j][i] == '1') {
                    v[j].eb(i);
                    break;
                }
            }
        }

        sort(all(num), [&v](int a, int b) {
            return v[a].size() > v[b].size();
        });
        
        vector <int> zero;
        while(!num.empty() && v[num.back()].empty()) {
            zero.eb(num.back());
            num.pop_back();
        }
        vector <int> ans(n);
        int idx = 0, cur = n - 1;
        for(int i : num) {
            int k = log_2[v[i].size()] + 1;
            ans[cur--] = i;
            for(int j : v[i]) {
                ans[cur--] = j;
            }
            for(int j = 0; j < (1 << k) - 1 - v[i].size(); j++) {
                ans[cur--] = zero[idx++];
            }
        }
        for(; idx < zero.size(); idx++) {
            ans[cur--] = zero[idx];
        }
        ans[0] = 1;
        print_ans(ans, n);
    }
}