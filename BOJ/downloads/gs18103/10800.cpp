#include <bits/stdc++.h>

using namespace std;

struct ball {
    int c, s, idx;
    long long ans;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector <ball> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].c >> v[i].s;
        v[i].idx = i;
    }

    sort(v.begin(), v.end(), [&](ball a, ball b) {
        return a.s < b.s;
    });
    vector <long long> cnt(n+1);
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        int st = i;
        for(; i + 1 < n && v[i+1].s == v[st].s; i++) ;
        for(int j = st; j <= i; j++) {
            v[j].ans = sum - cnt[v[j].c];
        }
        for(int j = st; j <= i; j++) {
            cnt[v[j].c] += v[j].s;
            sum += v[j].s;
        }
    }

    sort(v.begin(), v.end(), [&](ball a, ball b) {
        return a.idx < b.idx;
    });
    for(int i = 0; i < n; i++) {
        cout << v[i].ans << '\n';
    }
}