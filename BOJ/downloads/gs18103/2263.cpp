#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

int in[101010];
int pre[101010];
int post[101010];
int posi[101010];

void f(int l1, int r1, int l2, int r2)
{
    if(l1 > r1) return;
    int i = posi[post[r2]] - l1;
    printf("%d ", post[r2]);
    f(l1, l1 + i - 1, l2, l2 + i - 1);
    f(l1 + i + 1, r1, l2 + i, r2 - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &in[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &post[i]);
    for(int i = 1; i <= n; i++)
        posi[in[i]] = i;
    f(1, n, 1, n);
}
