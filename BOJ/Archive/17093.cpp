#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;

p a1[1010];
p a2[1010];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%lld %lld", &a1[i].first, &a1[i].second);
	for(int i = 0; i < m; i++) scanf("%lld %lld", &a2[i].first, &a2[i].second);

	ll ans = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			ans = max(ans, (a1[j].first-a2[i].first) * (a1[j].first-a2[i].first) + (a1[j].second-a2[i].second) * (a1[j].second-a2[i].second));
		}
	}
	printf("%lld", ans);
}