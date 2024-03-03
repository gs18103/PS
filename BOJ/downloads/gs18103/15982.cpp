#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define reset(x) memset(x, 0, sizeof(x))
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

set <int> st[2*MAX];
multiset <int> D;
int sum[MAX], p[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        if(p[i] == 0) p[i] = -1;
        sum[i] = sum[i-1] + p[i];
    }
    for(int i = 0; i <= n; i++) {
        st[sum[i]+MAX].em(i);
    }
    for(int i = MAX - n; i <= MAX + n; i++) {
        if(!st[i].empty()) D.em(*st[i].rbegin() - *st[i].begin());
    }
    cout << *D.rbegin() << '\n';
    for(int i = 1; i <= m; i++) {
        int pos;
        cin >> pos;
        if(p[pos] != p[pos+1]) {
            D.erase(D.find(*st[sum[pos]+MAX].rbegin() - *st[sum[pos]+MAX].begin()));
            D.erase(D.find(*st[sum[pos+1]+MAX].rbegin() - *st[sum[pos+1]+MAX].begin()));
            st[sum[pos]+MAX].erase(pos);
            st[sum[pos+1]+MAX].erase(pos+1);
            if(!st[sum[pos]+MAX].empty()) D.em(*st[sum[pos]+MAX].rbegin() - *st[sum[pos]+MAX].begin());
            if(!st[sum[pos+1]+MAX].empty()) D.em(*st[sum[pos+1]+MAX].rbegin() - *st[sum[pos+1]+MAX].begin());
            swap(p[pos], p[pos+1]);
            sum[pos] = sum[pos-1] + p[pos];
            sum[pos+1] = sum[pos] + p[pos+1];
            if(!st[sum[pos]+MAX].empty()) D.erase(D.find(*st[sum[pos]+MAX].rbegin() - *st[sum[pos]+MAX].begin()));
            if(!st[sum[pos+1]+MAX].empty()) D.erase(D.find(*st[sum[pos+1]+MAX].rbegin() - *st[sum[pos+1]+MAX].begin()));
            st[sum[pos]+MAX].em(pos);
            st[sum[pos+1]+MAX].em(pos+1);
            D.em(*st[sum[pos]+MAX].rbegin() - *st[sum[pos]+MAX].begin());
            D.em(*st[sum[pos+1]+MAX].rbegin() - *st[sum[pos+1]+MAX].begin());
        }
        cout << *D.rbegin() << '\n';
    }
}