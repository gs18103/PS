#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define em emplace

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;

vector <pii> g[MAX];
bool chk[MAX];
ll d[MAX];

int main() {
	  ios::sync_with_stdio(false);          
	  cin.tie(0);
	  
  int n;
  ll m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].eb(v, i);
    g[v].eb(u, i);
  }
  for(int i = 2; i <= n; i++) {
    d[i] = 1e18;
  }
  
  priority_queue <pll, vector <pll>, greater <pll> > pq;
  pq.em(0, 1);
  
  while(!pq.empty()) {
    int x = pq.top().se;
    pq.pop();
    if(chk[x]) continue;
    chk[x] = true;
    for(auto i : g[x]) {
      int y = i.fi;
      ll temp = ((d[x] - i.se + m) / m) * m + i.se;

      if(d[y] > temp) {
        d[y] = temp;
        pq.em(d[y], y);
      }
    }
  }
  cout << d[n];
}
