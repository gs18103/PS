#include <stdio.h>

int save[10010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        save[t]++;
    }
    for(int i = 1; i <= 10000; i++)
    {
        for(int j = 0; j < save[i]; j++)
        {
            printf("%d\n", i);
        }
    }
}
