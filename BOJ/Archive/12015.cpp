#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int arr[1010101], tree[1010101], n;
vector <int> num;

void update(int i, int val) {
    while(i <= n) {
        tree[i] = max(tree[i], val);
        i += (i & -i);
    }
}

int cal(int i) {
    int ret = 0;
    while(i) {
        ret = max(ret, tree[i]);
        i -= (i & -i);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        num.emplace_back(arr[i]);
    }
    sort(num.begin(), num.end());
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        arr[i] = lower_bound(num.begin(), num.end(), arr[i])-num.begin()+1;
        int tans = cal(arr[i]-1) + 1;
        update(arr[i], tans);
        ans = max(ans, tans);
    }
    cout << ans;
}