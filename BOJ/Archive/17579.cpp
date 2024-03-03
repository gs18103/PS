#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

bool solve() {
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0) return false;

    vector <int> a(n), w(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> w[i];
    }

    vector <int> sum;
    int sz = 1;
    for(int i = 0; i < m; i++) sz *= 3;
    for(int i = 0; i < sz; i++) {
        int tsum = 0, digit = 1;
        for(int j = 0; j < m; j++) {
            if((i / digit) % 3 == 1) tsum += w[j];
            else if((i / digit) % 3 == 2) tsum -= w[j];
            digit *= 3;
        }
        if(tsum >= 0) sum.eb(tsum);
    }

    set <int> st;
    st.em(0);
    bool flag2 = false;
    for(int i = 0; i < n; i++) {
        bool flag = false;
        for(auto j : sum) {
            if(j == a[i]) flag = true;
        }
        if(flag) continue;
        st.erase(0);
        if(!flag2) {
            for(auto j : sum) st.em(abs(j - a[i])), st.em(abs(j + a[i]));
            flag2 = true;
        }
        else {
            vector <int> tset;
            for(auto j : sum) {
                if(st.find(abs(j - a[i])) != st.end()) tset.eb(abs(j - a[i]));
                if(st.find(abs(j + a[i])) != st.end()) tset.eb(abs(j + a[i]));
            }
            st.clear();
            for(auto j : tset) st.em(j);
        }
    }
    if(st.empty()) cout << "-1\n";
    else cout << *st.begin() << '\n';

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    while(solve()) {}
}