#include <stdio.h>

long long save[8010];

int main()
{
    long long n, cnt = 0, i, j,median, mean = 0, mode;
    long long mini = 4000, maxi = -4000;
    scanf("%lld", &n);
    for(i = 1; i <= n; i++)
    {
        long long int t;
        scanf("%lld", &t);
        save[t + 4000]++;
    }
    int ncntmax = 0;
    for(i = 0; i <= 8000; i++)
    {
        for(j = 0; j < save[i]; j++)
        {
            cnt++;
            mean += (i-4000);
            if(cnt == n / 2 + 1) median = i - 4000;
            if(mini > i-4000) mini = i - 4000;
            if(maxi < i-4000) maxi = i - 4000;
        }
    }
    long long t = 0, maxcnt = 0;
    for(i = 0; i <= 8000; i++)
    {
        if(save[i] == maxcnt && t == 0)
        {
            mode = i - 4000;
            t = 1;
        }
        if(save[i] > maxcnt)
        {
            maxcnt = save[i];
            mode = i - 4000;
            t = 0;
        }
    }
    double m = (double)mean / n;
    if(m < 0)
    {
        m = -m;
        if((long long)(m * 10) % 10 < 5) m = -(long long)(m);
        else m = -(long long)(m) - 1;
    }
    else
    {
        if((long long)(m * 10) % 10 < 5) m = (long long)(m);
        else m = (long long)(m) + 1;
    }
    printf("%g\n%lld\n%lld\n%lld", m, median, mode, maxi-mini);
}
