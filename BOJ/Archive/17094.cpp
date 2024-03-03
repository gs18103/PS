#include <bits/stdc++.h>

using namespace std;

char x[101010];

int main()
{
	int n, t = 0, yee = 0;
	scanf("%d %s", &n, x);
	for(int i = 0; i < n; i++)
		if(x[i] == '2') t++;
		else yee++;

	if(yee > t) printf("e");
	else if(yee < t) printf("2");
	else printf("yee");
}