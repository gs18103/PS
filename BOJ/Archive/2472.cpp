#include <bits/stdc++.h>
#define INF 2010101010
#define MAX 101010

using namespace std;

typedef pair <int, int> p;

typedef struct 
{
	int a[3];
	int k;
} ord;

vector <p> g[MAX];
int d[3][MAX];
ord arr[MAX];
int tree[4*MAX];
bool ans[MAX];

bool cmp(ord x, ord y)
{
	if(x.a[0] < y.a[0]) return true;
	else if(x.a[0] == y.a[0])
	{
		if(x.a[1] > y.a[1]) return true;
		else return false;
	}
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
	if(s == e) return tree[node] = min(val, tree[node]);
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
	return min(mini(node*2, s, m, l , r), mini(node*2+1, m+1, e, l, r));
}

int main()
{
	int n, s[3], m;
	scanf("%d %d %d %d %d", &n, &s[0], &s[1], &s[2], &m);
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

	for(int i = 0; i < 3; i++)
	{
		priority_queue <p> pq;
		pq.push(p(0, s[i]));
		while(!pq.empty())
		{
			int x = pq.top().second;
			if(d[i][x] < INF)
			{
				pq.pop();
				continue;
			}
			d[i][x] = -pq.top().first;
			pq.pop();
			for(auto y : g[x])
			{
				if(d[i][y.first] == INF)
				{
					pq.push(p(-d[i][x] - y.second, y.first));
				}
			}
		}

		priority_queue <p> temp;
		for(int j = 1; j <= n; j++) temp.push(p(-d[i][j], j));
		int ind = 1;
		while(!temp.empty())
		{
			int x = temp.top().first;
			while(!temp.empty() && temp.top().first == x)
			{
				arr[temp.top().second].a[i] = ind;
				temp.pop();
			}
			ind++;
		}
	}
	for(int j = 1; j <= n; j++) arr[j].k = j;
	sort(arr+1, arr+1+n, cmp);
	
	init(1, 1, n);
	for(int i = 1; i <= n; i++)
	{
		if(mini(1, 1, n, 1, arr[i].a[1]) >= arr[i].a[2]) ans[arr[i].k] = true;
		update(1, 1, n, arr[i].a[1], arr[i].a[2]);
	}

	int Q;
	scanf("%d", &Q);
	for(int q = 0; q < Q; q++)
	{
		int t;
		scanf("%d", &t);
		if(ans[t])printf("YES\n");
		else printf("NO\n");
	}
}