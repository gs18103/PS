#include <cstdio>
#include <algorithm>
using namespace std;

int p[1010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    sort(p, p + n);

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += (n - i) * p[i];
    }
    printf("%d", ans);
}