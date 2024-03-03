#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a = 1, b = 3, c = 5;
	for(int i = 1; i < n; i++)
	{
		a = b;
		b = c;
		c = (2 * a + b) % 10007;
	}
	printf("%d", a);
}