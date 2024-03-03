#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 202020;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

int arr[MAX], bucket[505], sz = 400, ans[MAX], cnt[MAX], n, k;
list <int> dq[MAX];
struct Query {
    int l, r, idx;
} Q[MAX];

void add(int x, int t) {
    int temp = 0;
	if(!dq[arr[x]].empty()){
		temp = dq[arr[x]].back() - dq[arr[x]].front();
		cnt[temp]--;
		bucket[temp/sz]--;
	}
    if(t == 0) dq[arr[x]].push_front(x);
    else dq[arr[x]].push_back(x);
    temp = dq[arr[x]].back() - dq[arr[x]].front();
    cnt[temp]++, bucket[temp/sz]++;
}

void erase(int x, int t) {
    int temp = dq[arr[x]].back() - dq[arr[x]].front();
    cnt[temp]--, bucket[temp/sz]--;
    if(t == 0) dq[arr[x]].pop_front();
    else dq[arr[x]].pop_back();
    if(!dq[arr[x]].empty()) {
        temp = dq[arr[x]].back() - dq[arr[x]].front();
        cnt[temp]++, bucket[temp/sz]++;
    }
}

int get_ans(){
	for(int i = 500; i >= 0; i--){
		if(bucket[i] == 0) continue;
		for(int j = sz-1; j>=0; j--){
			if(cnt[i*sz+j] > 0){
				return i*sz+j;  
			}
		}
	}
	return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    n++;
    for(int i = 2; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i = 2; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i];
    }
    for(int i = 1; i <= n; i++) arr[i] += 100000;
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].r++;
        Q[i].idx = i;
    }
    sort(Q+1, Q+q+1, [](Query a, Query b) {
        int idxa = a.r / sz, idxb = b.r / sz;
        if(idxa == idxb) return a.l < b.l;
        return idxa < idxb;
    });
    int l = Q[1].l, r = Q[1].r;
    for(int i = l; i <= r; i++) add(i, 1);
    ans[Q[1].idx] = get_ans();
    for(int i = 2; i <= q; i++) {
        while(Q[i].l < l) {l--, add(l, 0);}
        while(Q[i].r > r) {r++; add(r, 1);}
        while(Q[i].r < r) {erase(r, 1); r--;}
        while(Q[i].l > l) {erase(l, 0); l++;}
        ans[Q[i].idx] = get_ans();
    }
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}