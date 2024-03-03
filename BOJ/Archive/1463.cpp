#include <stdio.h>
#include <algorithm>

using namespace std;

int d[1000001];

int f(int k)
{
    if(k == 1) return 0;
    if(d[k] != 0) return d[k];
    if(k % 2 == 0)
    {
        if(k % 3 == 0)
        {
            return d[k] = min(min(f(k / 2), f(k / 3)), f(k - 1)) + 1;
        }
        else return d[k] = min(f(k / 2), f(k - 1)) + 1;
    }
    else
    {
        if(k % 3 == 0)
        {
            return d[k] = min(f(k / 3), f(k - 1)) + 1;
        }
        else return d[k] = f(k - 1) + 1;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
}
