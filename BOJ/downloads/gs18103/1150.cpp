#include <bits/stdc++.h>
#define g(tp, x) get<x>(tp)

using namespace std;
typedef tuple <int, int, int> tp3;

int s[101010], sum[2][101010];
int n, L[101010], R[101010], p[101010];
bool chk[101010];
priority_queue <tp3, vector <tp3>, greater <tp3> > pq;

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

void uni(int x, int y) {
	x = find(x), y = find(y);
	if(x < y) swap(x, y);
	p[x] = y;
	L[y] = min(L[y], L[x]);
	R[y] = max(R[x], R[y]);
}

int solve() {
	int k, K;
	cin >> n >> k;
	K = k;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		L[i] = R[i] = p[i] = i;
	}
	while(!pq.empty()) pq.pop();
	memset(sum, 0, sizeof(sum));
	memset(chk, false, sizeof(chk));


	for(int i = 1; i < n; i++) {
		if(i & 1) sum[0][i+1] = sum[0][i] + s[i+1] - s[i], sum[1][i+1] = sum[1][i];
		else sum[1][i+1] = sum[1][i] + s[i+1] - s[i], sum[0][i+1] = sum[0][i];
		pq.push({s[i+1]-s[i], i, i+1});
	}

	int ans = 0;
	while(!pq.empty() && k) {
		int len = g(pq.top(), 0), l = g(pq.top(), 1), r = g(pq.top(), 2);
		pq.pop();
		if(chk[l] || chk[r]) continue;
		k--;
		chk[l] = true, chk[r] = true;
		ans += len;
		uni(l, r);
		if(chk[l-1]) uni(l, l-1);
		if(chk[r+1]) uni(l, r+1);
		if(L[find(l)]-1 > 0 && R[find(r)]+1 <= n) {
			l = L[find(l)]-1, r = R[find(r)]+1;
			pq.push({s[r]-s[l]-2*(sum[(r-1)%2][r-1]-sum[(r-1)%2][l]), l, r});
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cout << solve();
}