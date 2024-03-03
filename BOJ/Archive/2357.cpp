#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll tree[505050];
ll tree2[505050];
ll arr[505005];

ll init(int node, int s, int e)
{
	if(s == e) tree[node] = arr[s];
	else
	{
		ll M = (s + e) / 2;
		tree[node] = min(init(node*2, s, M), init(node*2+1, M+1, e));
	}
	return tree[node];
}

ll mini(int node, int s, int e, int l, int r)
{
	if(s >= l && e <= r) return tree[node];
	if(s > r || e < l) return 1000000000000000000;
	ll M = (s + e) / 2;
	return min(mini(node*2, s, M, l, r), mini(node*2+1, M+1, e, l, r));
}

ll init2(int node, int s, int e)
{
	if(s == e) return tree2[node] = arr[s];
	ll M = (s + e) / 2;
	return tree2[node] = max(init2(node*2, s, M), init2(node*2+1, M+1, e));
}

ll maxi(int node, int s, int e, int l, int r)
{
	if(s >= l && e <= r) return tree2[node];
	if(s > r || e < l) return 0;
	ll M = (s + e) / 2;
	return max(maxi(node*2, s, M, l, r), maxi(node*2+1, M+1, e, l, r));
}

int main()
{
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);

	init(1, 1, n);
	init2(1, 1, n);

	for(ll i = 0; i < m; i++)
	{
		ll a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld %lld\n", mini(1, 1, n, a, b), maxi(1, 1, n, a, b));
	}
}