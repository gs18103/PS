#include <stdio.h>
#include <string.h>

char num[20];
int save[10];

int main()
{
    scanf("%s", num);
    int len = strlen(num);
    for(int i = 0; i < len; i++)
    {
        int t = (int)(num[i] - '0');
        save[t]++;
    }
    for(int i = 9; i >= 0; i--)
        for(int j = 0; j < save[i]; j++)
            printf("%d", i);
}
