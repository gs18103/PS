#include <cstdio>
#include <map>

using namespace std;

map <long long, long long> dp;

#define m 100000

long long f(long long k)
{
    long long r;
    if(k == 0) return 0;
    if(k <= 2) return 1;
    if(dp.find(k) != dp.end())
    {
        return dp[k];
    }
    else
    {
        if(k % 2 == 0) r = f(k/2)*f(k/2)+2*f(k/2)*f(k/2-1);
        else r = f(k/2+1)*f(k/2+1)+f(k/2)*f(k/2);
        dp.insert(make_pair(k, r));
    }
    return r;
}

int main()
{
    long long n;
    scanf("%lld", &n);
    printf("%lld", f(n));
}
