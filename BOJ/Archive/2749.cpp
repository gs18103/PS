#include <cstdio>
#include <map>

#define m 1000000

using namespace std;

map <long long, long long> dp;

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
        if(k % 2 == 0) r = (f(k/2) * f(k/2) + 2 * f(k/2) * f(k/2-1)) % m;
        else r = (f(k/2+1) * f(k/2+1) + f(k/2) * f(k/2)) % m;
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
