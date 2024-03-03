#include <cstdio>
#include <string.h>

int stk[10001];
int num = 0;

char * empty = "empty";
char * size = "size";
char * top = "top";
char * push = "push";
char * pop = "pop";

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char x[6];
        scanf("%s", x);
        if(!strcmp(x, empty))
        {
            if(num == 0) printf("1\n");
            else printf("0\n");
        }
        if(!strcmp(x, size))
        {
            printf("%d\n", num);
        }
        if(!strcmp(x, top))
        {
            if(num == 0) printf("-1\n");
            else printf("%d\n", stk[num]);
        }
        if(!strcmp(x, push))
        {
            int temp;
            scanf("%d", &temp);
            stk[++num] = temp;
        }
        if(!strcmp(x, pop))
        {
            if(num == 0) printf("-1\n");
            else
            {
                printf("%d\n", stk[num]);
                stk[num--] = 0;
            }
        }
    }
}
