#include <cstdio>

long long catalan[5050];

int main()
{
    int T;
    scanf("%d", &T);

    catalan[0] = 1;
    for(int i = 1; i <= 2500; i++)
    {
        for(int j = 0; j < i; j++)
        {
            catalan[i] = (catalan[i] + catalan[j]*catalan[i-j-1]) % 1000000007;
        }
    }

    for(int i = 0; i < T; i++)
    {
        int l;
        scanf("%d", &l);
        if(l % 2 == 1) printf("0\n");
        else printf("%lld\n", catalan[l/2]);
    }
}
