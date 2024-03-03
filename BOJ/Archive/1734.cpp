#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define g(tp, x) get<(x)>(tp)
#define INF 2000000000
#define LINF 1000000000000000000LL
#define MAX_N 101010

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

vector <int> g[MAX_N], chi[MAX_N];
int low[MAX_N], ord[MAX_N], out[MAX_N];
bool chk[MAX_N];

int cnt = 0;
int dfs(int x, int p) {
	chk[x] = true;
	low[x] = ord[x] = out[x] = ++cnt;
	for(auto i : g[x]) {
		if(i == p) continue;
		if(chk[i]) {
			low[x] = min(low[x], ord[i]);
		}
		else {
			out[x] = max(out[x], dfs(i, x));
			low[x] = min(low[x], low[i]);
			chi[x].eb(i);
		}
	}
	return out[x];
}

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1, 0);
	int q;
	cin >> q;
	while(q--) {
		int mode;
		cin >> mode;
		if(mode == 1) {
			int a, b, u, v, flag = 0;
			cin >> a >> b >> u >> v;
			if(low[u] > ord[v]) {
				if(ord[u] <= ord[a] && out[a] <= out[u]) flag++;
				if(ord[u] <= ord[b] && out[b] <= out[u]) flag++;
				if(flag == 1) cout << "no\n";
				else cout << "yes\n";
			}
			else if(low[v] > ord[u]) {
				if(ord[v] <= ord[a] && out[a] <= out[v]) flag++;
				if(ord[v] <= ord[b] && out[b] <= out[v]) flag++;
				if(flag == 1) cout << "no\n";
				else cout << "yes\n";
			}
			else cout << "yes\n";
		}
		else if(mode == 2){
			int a, b, c, flag = 0;
			cin >> a >> b >> c;
			for(auto i : chi[c]) {
				flag = 0;
				if(low[i] < ord[c] && c != 1) continue;
				if(ord[i] <= ord[a] && ord[a] <= out[i]) flag++;
				if(ord[i] <= ord[b] && ord[b] <= out[i]) flag++;
				if(flag == 1) break;
			}
			if(flag % 2 == 1) cout << "no\n";
			else cout << "yes\n";
		}
	}
	return 0;
}