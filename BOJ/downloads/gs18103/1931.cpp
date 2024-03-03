#include <bits/stdc++.h>

using namespace std;

struct ST {
    int s, e;
};

ST arr[101010];

bool cmp(ST a, ST b) {
    if(a.e == b.e) return a.s < b.s;
    return a.e < b.e;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].s >> arr[i].e;
    }

    sort(arr+1, arr+n+1, cmp);
    int ans = 0, ed = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i].s < ed) continue;
        ans++;
        ed = arr[i].e;
    }
    cout << ans;
}