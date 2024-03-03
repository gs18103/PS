/*
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
}*/



/*
#include <stdio.h>

int main()
{
    int T, n;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        int a = 1, b = 2, c = 4;
        for(int j = 1; j < n; j++)
        {
            int t = a;
            a = b;
            b = c;
            c = a + b + t;
        }
        printf("%d\n", a);
    }
}*/

/*
#include <stdio.h>
#include <algorithm>

using namespace std;

int score_Max[301][3];
int score[301], n;

int f(int k, int r)
{
    if(k <= 0) return 0;
    if(k == 1) return score[1];
    if(score_Max[k][r] != 0) return score_Max[k][r];

    if(r == 0) score_Max[k][r] = max(f(k - 2, 0), f(k - 2, 1)) + score[k];
    else score_Max[k][r] = f(k - 1, r - 1) + score[k];
    return score_Max[k][r];
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &score[i]);
    printf("%d", max(f(n, 0), f(n, 1)));
}*/

/*
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, minimum_cost[3][1001];
int cost[3][1001];

int f(int k, int c)
{
    if(k == 0) return 0;
    if(minimum_cost[c][k] != 0) return minimum_cost[c][k];
    if(c == 0) return minimum_cost[c][k] = min(f(k - 1, 1), f(k - 1, 2)) + cost[c][k];
    if(c == 1) return minimum_cost[c][k] = min(f(k - 1, 2), f(k - 1, 0)) + cost[c][k];
    if(c == 2) return minimum_cost[c][k] = min(f(k - 1, 0), f(k - 1, 1)) + cost[c][k];
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d %d %d", &cost[0][i], &cost[1][i], &cost[2][i]);
    printf("%d", min(f(n, 0), min(f(n, 1), f(n, 2))));
}*/


/*
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long int a = 1, b = 1;
    for(int i = 1; i < n; i++)
    {
        long long int t = a;
        a = b;
        b = a + t;
    }
    printf("%lld", a);
}*/

#include <stdio.h>

int d[41];

int f(int k)
{
    if(k == -2) return 1;
    if(k == -1) return 0;
    if(k == 0) return 1;
    if(k == 1) return 1;
    if(d[k] != 0) return d[k];
    return d[k] = f(k - 1) + f(k - 2);
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%d %d\n", f(n - 2), f(n - 1));
    }
}
