#include <bits/stdc++.h>
#define INF 1010101010
#define MAX 501010

using namespace std;

typedef pair<int, int> p;
typedef struct 
{
	int prize[3];
	int k;
} dist;

int tree[4*MAX];
dist arr[MAX];
int d[3][MAX];
p tarr[MAX];
bool ans[MAX];
bool chk[3][MAX];
vector <p> g[MAX];

bool cmp(dist a, dist b)
{
	if(a.prize[1] < b.prize[1]) return true;
	else if(a.prize[1] == b.prize[1] && a.prize[0] > b.prize[0]) return true;
	else return false;
}

void init(int node, int s, int e)
{
	tree[node] = INF;
	if(s == e) return;
	int m = (s + e) / 2;
	init(node*2, s, m);
	init(node*2+1, m+1, e);
}

int update(int node, int s, int e, int k, int val)
{
	if(s == e) return tree[node] = min(tree[node], val);
	int m = (s + e) / 2;
	if(k <= m) return tree[node] = min(update(node*2, s, m, k, val), tree[node*2+1]);
	else return tree[node] = min(update(node*2+1, m+1, e, k, val), tree[node*2]);
}

int mini(int node, int s, int e, int l, int r)
{
	if(l > r) return INF;
	if(s > r || e < l) return INF;
	if(s >= l && e <= r) return tree[node];
	int m = (s + e) / 2;
	return min(mini(node*2, s, m, l ,r), mini(node*2+1, m+1, e, l, r));
}

int main()
{
	/*int n, Cof[3], m;
	scanf("%d %d %d %d %d", &n, &Cof[0], &Cof[1], &Cof[2], &m);
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back(p(v, w));
		g[v].push_back(p(u, w));
	}

	for(int i = 0; i < 3; i++)
		for(int j = 1; j <= n; j++)
			d[i][j] = INF;

	//dijkstra
	for(int i = 0; i < 3; i++)
	{
		priority_queue <p> pq;
		pq.push(p(0, Cof[i]));
		d[i][Cof[i]] = 0;
		while(!pq.empty())
		{
			int x = pq.top().second;
			pq.pop();
			if(chk[i][x]) continue;
			chk[i][x] = true;
			for(auto y : g[x])
			{
				if(d[i][y.first] > y.second + d[i][x])
				{
					d[i][y.first] = d[i][x] + y.second;
					pq.push(p(-d[i][y.first], y.first));
				}
			}
		}
	}

	for(int i = 0; i < 3; i++)
	{
		int ind = 1;
		for(int j = 1; j <= n; j++)
		{
			tarr[j] = p(d[i][j], j);
		}
		sort(tarr+1, tarr+n+1);
		for(int j = 1; j <= n; j++)
		{
			arr[tarr[j].second].prize[i] = ind;
			arr[tarr[j].second].k = tarr[j].second;
			if(tarr[j].first != tarr[j+1].first) ind++;
		}
	}
	*/

	// amazing student
	int n;
	scanf("%d", &n);

	for(int i = 0; i < 3; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int t;
			scanf("%d", &t);
			arr[t].prize[i] = j;
			arr[j].k = j;
		}
	}
	//

	sort(arr+1, arr+n+1, cmp);

	init(1, 1, n);
	for(int i = 1; i <= n; i++)
	{
		//printf("%d %d %d\n", arr[i].prize[0], mini(1, 1, n, 1, arr[i].prize[0]-1), arr[i].prize[2]);
		if(mini(1, 1, n, 1, arr[i].prize[0]-1) >= arr[i].prize[2]) ans[arr[i].k] = true;
		else ans[arr[i].k] = false;
		update(1, 1, n, arr[i].prize[0], arr[i].prize[2]);
	}

	//
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(ans[i]) cnt++;

	printf("%d", cnt);

	//

	/*
	int Q;
	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++)
	{
		int t;
		scanf("%d", &t);
		if(ans[i]) printf("YES\n");
		else printf("NO\n");
	}
	*/
}