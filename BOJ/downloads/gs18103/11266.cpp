#include <bits/stdc++.h>

using namespace std;

vector <int> g[101010], c[101010];
int low[101010], ord[101010];
pair <int, int> edge[101010];
bool chk[101010];

int d = 0;
void DFS(int x) {
	chk[x] = true;
	ord[x] = ++d;
	low[x] = d;
	for(int i : g[x]) {
		if(chk[i]) {
			low[x] = min(low[x], ord[i]);
		}
		else {
			DFS(i);
			c[x].push_back(i);
			low[x] = min(low[x], low[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int V, E;
	cin >> V >> E;
	for(int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	set <int> root;
	for(int i = 1; i <= V; i++) {
		if(!chk[i]) {
			DFS(i);
			root.insert(i);
		}
	}

	vector <int> ans;
	int cnt = 0;
	for(int i = 1; i <= V; i++) {
		if(root.find(i) != root.end()) {
			if(c[i].size() > 1) {
				cnt++;
				ans.push_back(i);
			}
			continue;
		}
		bool flag = false;
		for(int j : c[i]) {
			if(low[j] >= ord[i]) {
				flag = true;
				break;
			}
		}
		if(c[i].empty()) continue;
		if(!flag) continue;
		cnt++;
		ans.push_back(i);
	}
	cout << cnt << "\n";
	for(int i : ans) {
		cout << i << ' ';
	}
}