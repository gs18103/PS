#include <cstdio>
#include <map>

#define m 1000000007

using namespace std;

int f(int k)
{
    if(k == 0) return 0;
    else if(k == 1) return 1;
    return f(k - 1) + f(k - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
}
