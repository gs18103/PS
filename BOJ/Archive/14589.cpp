#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 202020;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

struct segment {
    int l, r, idx, nex[20];
} arr[MAX];
int trans[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].l >> arr[i].r;
        arr[i].idx = i;
    }
    sort(arr+1, arr+n+1, [](segment a, segment b){
        if(a.r == b.r) return a.l < b.l;
        return a.r < b.r;
    });
    arr[n].nex[0] = n;
    int end = n;
    for(int i = n - 1; i > 0; i--) {
        while(end > i && arr[end].l > arr[i].r) end--;
        arr[i].nex[0] = end;
    }
    for(int i = 1; i <= n; i++) {
        trans[arr[i].idx] = i;
    }
    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) {
            arr[j].nex[i] = arr[arr[j].nex[i-1]].nex[i-1];
        }
    }
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        a = trans[a], b = trans[b];
        if(a > b) swap(a, b);
        if(arr[a].r >= arr[b].l) {
            cout << "1\n";
            continue;
        }
        int ans = 0;
        for(int i = 19; i >= 0; i--) {
            if(arr[arr[a].nex[i]].r < arr[b].l) {
                a = arr[a].nex[i];
                ans += (1 << i);
            }
        }
        ans += 2;
        a = arr[a].nex[1];
        if(a < b) cout << "-1\n";
        else cout << ans << '\n';
    }
}