#include <bits/stdc++.h>

using namespace std;

int a[101], b[101];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	sort(a, a+n);
	sort(b, b+n);
	int s = 0;
	for(int i = 0; i < n; i++) s += a[i] * b[n-i-1];
	printf("%d", s);
}