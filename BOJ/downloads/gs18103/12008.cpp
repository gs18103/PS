#include <bits/stdc++.h>

using namespace std;

stack <int> s[60];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		s[0].push(t);
	}

	for(int i = 1; i <= 59; i++)
	{
		int cnt = 0;
		while(!s[i-1].empty())
		{
			if(s[i-1].top() == i) cnt++;
			else if(cnt >= 1)
			{
				for(int j = 0; j < cnt/2; j++) s[i].push(i+1);
				if(cnt % 2 == 1)
				{
					s[i].push(i);
					for(int j = 0; j < cnt/2; j++) s[i].push(i+1);
				}
				s[i].push(s[i-1].top());
				cnt = 0;
			}
			else
			{
				s[i].push(s[i-1].top());
				cnt = 0;
			}
			s[i-1].pop();
		}
		if(cnt >= 1)
		{
			for(int j = 0; j < cnt/2; j++) s[i].push(i+1);
			if(cnt % 2 == 1)
			{
				s[i].push(i);
				for(int j = 0; j < cnt/2; j++) s[i].push(i+1);
			}
		}
	}

	int ans = 0;
	while(!s[59].empty())
	{
		ans = max(ans, s[59].top());
		s[59].pop();
	}
	printf("%d", ans);
}