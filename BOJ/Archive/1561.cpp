#include <cstdio>

long long arr[10101];

int main ()
{
    long long n, m;
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf ("%lld", &arr[i]);
    }

    if(n <= m)
    {
        printf("%d\n", n);
        return 0;
    }

    long long l = 0LL, r = 30LL * n, cnt;
    while(l < r)
    {
        long long mid = (l+r)/2;
        cnt = 0;
        for (int i = 0; i < m; i++)
            cnt += mid / arr[i];
        if(cnt + m >= n) r = mid;
        else l = mid + 1;
    }
    cnt = (long long)m;
    for(int i = 0; i < m; i++)
    {
        cnt += (l - 1) / arr[i];
    }

    for(int i = 0; i < m; i++)
    {
        if(l % arr[i] == 0) cnt++;
        if(cnt == n)
        {
            printf ("%d", i+1);
            return 0;
        }
    }
}
