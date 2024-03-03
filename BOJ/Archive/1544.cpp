#include <stdio.h>
#include <string.h>

char x[50][101], word[101];
int len[50];

int main()
{
	int n, t = 1;
	scanf("%d", &n);
	scanf("%s", x[0]);
	len[0] = strlen(x[0]);
	for(int i = len[0]; i < len[0] * 2; i++)
	{
		x[0][i] = x[0][i-len[0]];
	}
	
	for(int i = 1; i < n; i++)
	{
		scanf("%s", word);
		int temp = 0;
		for(int j = 0; j < t; j++)
		{
			if(strlen(word) == len[j])
			{
				for(int k = 0; k < len[j]; k++)
				{
					temp = 0;
					for(int l = 0; l < len[j]; l++)
					{
						if(word[l] != x[j][k+l])
						{
							temp = 1;
							break;
						}
					}
					if(temp == 0) break;
				}
				if(temp == 0) break;
			}
			else temp = 1;
		}
		if(temp == 1)
		{
			len[t] = strlen(word);
			for(int i = 0; i < len[t]; i++)
			{
				x[t][i] = word[i];
				x[t][i+len[t]] = word[i];
			}
			t++;
		}
	}
	printf("%d", t);
}