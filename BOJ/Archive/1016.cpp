#include <cstdio>

bool chk[1010000];

int main()
{
    long long min, max;

    scanf("%lld %lld", &min, &max);

    for(long long i = 2; i * i <= max; i++)
    {
        for(long long j = min / (i * i); j * i * i <= max; j++)
        {
            if(j * i * i >= min) chk[j*i*i-min] = true;
        }
    }

    int cnt = 0;
    for(int i = 0; i <= max - min; i++)
        if(chk[i] == false) cnt++;
    printf("%d", cnt);
}
